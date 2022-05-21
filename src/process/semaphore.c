/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: semapore api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-21     JasonHu           Init
 */

#include <nxbase/syscall.h>
#include <nxbase/process.h>
#include <nxbase/error.h>

NX_Solt NX_SemaphoreCreate(NX_IArch value)
{
    NX_Solt solt = NX_SOLT_INVALID_VALUE;
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall2(NX_API_SemaphoreCreate, value, &solt)));
    return solt;
}

NX_Error NX_SemaphoreDestroy(NX_Solt solt)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall1(NX_API_SemaphoreDestroy, solt)));
    return err;
}

NX_Error NX_SemaphoreWait(NX_Solt solt)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall1(NX_API_SemaphoreWait, solt)));
    return err;
}

NX_Error NX_SemaphoreTryWait(NX_Solt solt)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall1(NX_API_SemaphoreTryWait, solt)));
    return err;
}

NX_Error NX_SemaphoreSignal(NX_Solt solt)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall1(NX_API_SemaphoreSignal, solt)));
    return err;
}

NX_Error NX_SemaphoreSignalAll(NX_Solt solt)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall1(NX_API_SemaphoreSignalAll, solt)));
    return err;
}

NX_IArch NX_SemaphoreGetValue(NX_Solt solt)
{
    NX_Error err;
    NX_IArch value = 0;

    NX_ErrorSet((err = NX_Syscall2(NX_API_SemaphoreGetValue, solt, &value)));
    return value;
}
