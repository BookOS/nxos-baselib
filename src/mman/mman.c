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

#include <nxbase/mman.h>
#include <nxbase/syscall.h>

void * NX_MemMap(void * addr, NX_Size length, NX_U32 prot, NX_Error * outErr)
{
    return (void *)NX_Syscall4(NX_API_MemMap, addr, length, prot, outErr);
}

NX_Error NX_MemUnmap(void * addr, NX_Size length)
{
    return NX_Syscall2(NX_API_MemUnmap, addr, length);
}

void * NX_MemHeap(void * addr, NX_Error * outErr)
{
    return (void *)NX_Syscall2(NX_API_MemHeap, addr, outErr);
}
