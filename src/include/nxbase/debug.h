/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: debug api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-3-19      JasonHu           Init
 */

#ifndef __NXBASE_DEBUG__
#define __NXBASE_DEBUG__

#include <nxbase/xbook.h>

NX_Error NX_DebugLog(char *buf, NX_Size len);

#endif  /* __NXBASE_DEBUG__ */
