/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: c run time
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-2-9       JasonHu           Init
 */

#include <nxbase/process.h>

extern NX_Error NX_Main(char *cmdline);

void __NX_StartC(long *p)
{
    NX_Error err = NX_Main(0);
    NX_ProcessExit(err);
    while (1);
}
