/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: thread
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-15     JasonHu           Init
 */

#include <nxbase/syscall.h>
#include <nxbase/process.h>

NX_Error NX_ThreadCreate(NX_ThreadAttr * attr, void (*handler)(void *), void * arg, NX_U32 flags, NX_Solt * outSolt)
{
    return NX_Syscall5(NX_API_ThreadCreate, attr, handler, arg, flags, outSolt);
}

void NX_ThreadExit(void)
{
    NX_Syscall0(NX_API_ThreadExit);
}

NX_Error NX_ThreadSuspend(NX_Solt solt)
{
    return NX_Syscall1(NX_API_ThreadSuspend, solt);
}

NX_Error NX_ThreadResume(NX_Solt solt)
{
    return NX_Syscall1(NX_API_ThreadResume, solt);
}

NX_Error NX_ThreadWait(NX_Solt solt)
{
    return NX_Syscall1(NX_API_ThreadWait, solt);
}
