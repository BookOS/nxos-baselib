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
#include <nxbase/utils.h>

extern NX_Error NX_Main(char *cmdline, char *envline);

void __NX_StartC(NX_Addr *p)
{    
    char *cmdline;
    char *envline;

    char **args = (char **)p;

    cmdline = args[0];
    envline = args[1];
    NX_Error err = NX_Main(cmdline, envline);
    NX_ProcessExit(err);
    while (1);
}
