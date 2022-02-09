/**
 * Copyright (c) 2018-2022, BookOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: c run time
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-2-9       JasonHu           Init
 */

extern int NX_Main(char *cmdline);

void __NX_StartC(long *p)
{
    NX_Main(0);
    while (1);
}
