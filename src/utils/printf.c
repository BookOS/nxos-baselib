/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: print format
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-1       JasonHu           Init
 */

#include <nxbase/utils.h>
#include <nxbase/debug.h>

#define NX_PRINT_BUF_LEN 1024

void NX_Printf(const char *fmt, ...)
{
	char buf[NX_PRINT_BUF_LEN] = {0};
	NX_VarList arg;
    NX_VarStart(arg, fmt);
    int len = NX_StrPrintfVarN(buf, NX_PRINT_BUF_LEN, fmt, arg);
	NX_VarEnd(arg);
    NX_DebugLog(buf, (NX_Size)len);
}
