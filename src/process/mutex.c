/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: mutex api 
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-21     JasonHu           Init
 */

#include <nxbase/syscall.h>
#include <nxbase/process.h>
#include <nxbase/error.h>

NX_Solt NX_MutexCreate(NX_U32 attr)
{
    NX_Solt solt = NX_SOLT_INVALID_VALUE;
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall2(NX_API_MutexCreate, attr, &solt)));
    return solt;
}

NX_Error NX_MutexDestroy(NX_Solt solt)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall1(NX_API_MutexDestroy, solt)));
    return err;
}

NX_Error NX_MutexAcquire(NX_Solt solt)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall1(NX_API_MutexAcquire, solt)));
    return err;
}

NX_Error NX_MutexTryAcquire(NX_Solt solt)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall1(NX_API_MutexTryAcquire, solt)));
    return err;
}

NX_Error NX_MutexRelease(NX_Solt solt)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall1(NX_API_MutexRelease, solt)));
    return err;
}

NX_Error NX_MutexAcquirable(NX_Solt solt)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall1(NX_API_MutexAcquirable, solt)));
    return err;
}
