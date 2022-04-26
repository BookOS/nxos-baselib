/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: process api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-3-19      JasonHu           Init
 */

#ifndef __NXBASE_PROCESS__
#define __NXBASE_PROCESS__

#include <nxbase/xbook.h>

#define NX_PROC_FLAG_NOWAIT 0x00
#define NX_PROC_FLAG_WAIT 0x01

void NX_ProcessExit(int exitCode);
NX_Error NX_ProcessLaunch(char *path, NX_U32 flags, int *retCode, char *cmd, char *env);

#endif  /* __NXBASE_PROCESS__ */
