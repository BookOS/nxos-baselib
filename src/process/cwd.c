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

NX_Error NX_ProcessGetCwd(char * buf, NX_Size length)
{
    return NX_Syscall2(NX_API_ProcessGetCwd, buf, length);
}

NX_Error NX_ProcessSetCwd(char * buf)
{
    return NX_Syscall1(NX_API_ProcessSetCwd, buf);
}
