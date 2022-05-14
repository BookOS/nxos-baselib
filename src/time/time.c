/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: time
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-14     JasonHu           Init
 */

#include <nxbase/syscall.h>
#include <nxbase/time.h>

NX_Error NX_TimeSet(NX_Time * time)
{
    return NX_Syscall1(NX_API_TimeSet, time);
}

NX_Error NX_TimeGet(NX_Time * time)
{
    return NX_Syscall1(NX_API_TimeGet, time);
}
