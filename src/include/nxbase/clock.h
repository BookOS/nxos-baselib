/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: clock api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-13     JasonHu           Init
 */

#ifndef __NXBASE_CLOCK_H__
#define __NXBASE_CLOCK_H__

#include <nxbase/xbook.h>

typedef NX_UArch NX_TimeVal;
typedef NX_UArch NX_ClockTick;

NX_TimeVal NX_ClockGetMillisecond(void);

#endif  /* __NXBASE_CLOCK_H__ */
