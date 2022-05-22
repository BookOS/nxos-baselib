/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: simple memory alloctor
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-23     JasonHu           Init
 */

#include <nxbase/mman.h>
#include <nxbase/syscall.h>
#include <nxbase/utils.h>

#define NX_MEM_BLOCK_ALIGN(x) NX_ALIGN_UP((x), sizeof(NX_Size))
#define NX_MEM_BLOCK_SIZE (5 * sizeof(NX_Size))

typedef struct NX_MemBlockStruct * NX_MemBlockPtr;
struct NX_MemBlockStruct
{
    /* meta */
    NX_Size size;
    NX_MemBlockPtr next;
    NX_MemBlockPtr prev;
    NX_Size free;
    void* ptr;
    /* data */
    char data[1];
};

NX_PRIVATE NX_MemBlockPtr memBlockBase = NX_NULL;

NX_PRIVATE NX_MemBlockPtr FindBlock(NX_MemBlockPtr * last, NX_Size size)
{
    NX_MemBlockPtr b = memBlockBase;
    while (b && !(b->free && b->size >= size))
    {
        *last = b;
        b = b->next;
    }
    return b;
}

NX_PRIVATE NX_MemBlockPtr ExtendHead(NX_MemBlockPtr last, NX_Size size)
{
    NX_MemBlockPtr b;
    b = NX_PosixSbrk(0);
    
    if ((void*)-1 == NX_PosixSbrk(NX_MEM_BLOCK_SIZE + size))
    {
        return NX_NULL;
    }

    b->size = size;
    b->next = NX_NULL;
    b->prev = last;
    if (last)
    {
        last->next  = b;
    }

    b->ptr = b->data;
    b->free = 0;
    return b;
}

NX_PRIVATE void SplitBlock(NX_MemBlockPtr b, NX_Size s)
{
    if (!b)
    {
        return;
    }

    NX_MemBlockPtr new; 
    new = (NX_MemBlockPtr)(b->data + s);
    new->size = b->size - s - NX_MEM_BLOCK_SIZE;
    new->free = 1;

    new->next = b->next; 
    b->next->prev = new;
    new->prev = b;
    b->size = s;
    b->next = new;
}

NX_PRIVATE NX_MemBlockPtr MergeBlock(NX_MemBlockPtr b)
{
    if (b->next && b->next->free)
    {
        b->size += NX_MEM_BLOCK_SIZE + b->next->free;
        b->next = b->next->next ;
        if ( b->next)
        {
            b->next->prev = b;
        }
    }
    return b;
}

NX_PRIVATE NX_MemBlockPtr PtrToBlock(void * p)
{
    char * tmp;
    tmp = p;
    tmp -= NX_MEM_BLOCK_SIZE;
    p = tmp;
    return p;
}

NX_PRIVATE void CopyBlock(NX_MemBlockPtr src, NX_MemBlockPtr dst)
{
    int * sdata , * ddata;
    NX_Size i;
    sdata = src ->ptr;
    ddata = dst ->ptr;
    for (i = 0; i * 4 < src->size && i * 4 < dst->size; i++)
    {
        ddata[i] = sdata[i];
    }
}

NX_PRIVATE int ValidAddr(void * p)
{
    if (memBlockBase)
    {
        if ( p > (void *)memBlockBase && p < NX_PosixSbrk(0)) 
        {
            return p == (PtrToBlock(p)->ptr);
        }
    }
    return 0;
}

void * NX_MemAlloc(NX_Size size)
{
    NX_MemBlockPtr last, b;
    NX_Size alignSize = NX_MEM_BLOCK_ALIGN(size);

    if (memBlockBase)
    {
        last = memBlockBase;
        if ((b = FindBlock(&last, alignSize)))
        {
            if (b->size - alignSize >= (NX_MEM_BLOCK_SIZE + sizeof(NX_Size)))
            {
                SplitBlock(b, alignSize);
            }
            b->free = 0;
        }
        else
        {
            b = ExtendHead(memBlockBase, alignSize);
            if (!b)
            {
                return NX_NULL;
            }
        }
    }
    else
    {
        b = ExtendHead(memBlockBase, alignSize);
        if (!b)
        {
            return NX_NULL;
        }
        memBlockBase = b;
    }
 
    return b->data;
}

void * NX_MemAllocEx(NX_Size number, NX_Size size)
{
    NX_Size * newp;
    newp = NX_MemAlloc(number * size);
    if (newp)
    {
        NX_MemZero(newp, NX_MEM_BLOCK_ALIGN(number * size));
    }
    return newp;
}

void * NX_MemReAlloc(void * p, NX_Size size)
{
    NX_Size s;
    NX_MemBlockPtr b, new;
    void *newp;
    
    if (!p)
    {
        return NX_MemAlloc(size);
    }

    if (ValidAddr(p))
    {
        s = NX_MEM_BLOCK_ALIGN(size);
        b = PtrToBlock(p);
        if (b->size >= s)
        {
            if (b->size - s >= (NX_MEM_BLOCK_SIZE + sizeof(NX_Size)))
            {
                SplitBlock(b,s);
            }
        }
        else
        {
            /* Try MergeBlock with next if possible */
            if (b->next && b->next->free && (b->size + NX_MEM_BLOCK_SIZE + b->next->size) >= s)
            {
                MergeBlock(b);
                if (b->size - s >= (NX_MEM_BLOCK_SIZE + sizeof(NX_Size)))
                {
                    SplitBlock (b, s);
                }
            }
            else
            {
                /* good old NX_MemReAlloc with a new block */
                newp = NX_MemAlloc(s);
                if (!newp)
                {
                    /* we’re doomed ! */
                    return (NX_NULL );                    
                }
                /* I assume this work ! */
                new = PtrToBlock (newp);
                /* Copy data */
                CopyBlock (b,new );
                /* free the old one */
                NX_MemFree(p);
                return newp;
            }
        }
        return p;
    }
    return NX_NULL;
}

void NX_MemFree(void * ptr)
{
    NX_MemBlockPtr b;

    if (ValidAddr(ptr))
    {
        b = PtrToBlock(ptr); 
        b->free = 1;
 
        if (b->prev && b->prev->free)
        {
            b = MergeBlock(b->prev);
        }
 
        if (b->next)
        {
            MergeBlock(b);
        }
        else
        {
            if (b->prev)
            {
                b->prev->next = NX_NULL;
            }
            else 
            {
                memBlockBase = NX_NULL;
            }
            NX_PosixBrk(b);
        }
    }
}
