/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: clock
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-13     JasonHu           Init
 */

#include <nxbase/syscall.h>
#include <nxbase/clock.h>

NX_TimeVal NX_ClockGetMillisecond(void)
{
    return NX_Syscall0(NX_API_ClockGetMillisecond);
}
