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

NX_PRIVATE NX_ThreadAttr __defaultThreadAttr = NX_THREAD_ATTR_INIT;

NX_Error NX_ThreadCreate(NX_ThreadAttr * attr, NX_U32 (*handler)(void *), void * arg, NX_U32 flags, NX_Solt * outSolt)
{
    if (!attr)
    {
        attr = &__defaultThreadAttr;
    }

    return NX_Syscall5(NX_API_ThreadCreate, attr, handler, arg, flags, outSolt);
}

void NX_ThreadExit(NX_U32 exitCode)
{
    NX_Syscall1(NX_API_ThreadExit, exitCode);
}

NX_Error NX_ThreadSuspend(NX_Solt solt)
{
    return NX_Syscall1(NX_API_ThreadSuspend, solt);
}

NX_Error NX_ThreadResume(NX_Solt solt)
{
    return NX_Syscall1(NX_API_ThreadResume, solt);
}

NX_Error NX_ThreadWait(NX_Solt solt, NX_U32 * exitCode)
{
    return NX_Syscall2(NX_API_ThreadWait, solt, exitCode);
}

NX_Error NX_ThreadTerminate(NX_Solt solt, NX_U32 exitCode)
{
    return NX_Syscall2(NX_API_ThreadTerminate, solt, exitCode);
}

NX_Error NX_ThreadAttrInit(NX_ThreadAttr * attr, NX_Size stackSize, NX_U32 schedPriority)
{
    if (!attr || !stackSize)
    {
        return NX_EINVAL;
    }

    if (schedPriority < NX_THREAD_PRIORITY_LOW)
    {
        schedPriority = NX_THREAD_PRIORITY_LOW;
    }

    if (schedPriority > NX_THREAD_PRIORITY_HIGH)
    {
        schedPriority = NX_THREAD_PRIORITY_HIGH;
    }

    attr->stackSize = stackSize;
    attr->schedPriority = schedPriority;
    return NX_EOK;
}
