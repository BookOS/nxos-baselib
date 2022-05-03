/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: solt close
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-03     JasonHu           Init
 */

#include <nxbase/syscall.h>
#include <nxbase/process.h>

NX_Error NX_SoltClose(NX_Solt solt)
{
    return NX_Syscall1(NX_API_SoltClose, solt);
}
