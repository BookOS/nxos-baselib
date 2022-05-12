/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: get/set current work directory
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-27      JasonHu           Init
 */

#include <nxbase/syscall.h>

NX_Error NX_ThreadSleep(NX_UArch microseconds)
{
    return NX_Syscall1(NX_API_ThreadSleep, microseconds);
}
