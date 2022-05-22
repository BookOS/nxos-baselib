/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: memory management api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-20      JasonHu           Init
 */

#ifndef __NXBASE_MMAN_H__
#define __NXBASE_MMAN_H__

#include <nxbase/xbook.h>

#define NX_PROT_READ    0x01    /* mem readable */
#define NX_PROT_WRITE   0x02    /* mem writable */
#define NX_PROT_EXEC    0x04    /* mem executeable */

void * NX_MemMap(void * addr, NX_Size length, NX_U32 prot, NX_Error * outErr);
NX_Error NX_MemUnmap(void * addr, NX_Size length);
void * NX_MemHeap(void * addr, NX_Error * outErr);

int NX_PosixBrk(void * addr);
void * NX_PosixSbrk(int increment);

void * NX_MemAlloc(NX_Size size);
void * NX_MemAllocEx(NX_Size number, NX_Size size);
void * NX_MemReAlloc(void * p, NX_Size size);
void NX_MemFree(void * ptr);

#endif  /* __NXBASE_MMAN_H__ */
