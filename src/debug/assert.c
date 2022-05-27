/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: assert
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-22     JasonHu           Init
 */

#include <nxbase/utils.h>

#ifdef NX_DEBUG
void NX_AssertionFailure(char *exp, char *file, char *baseFile, int line)
{
    NX_Printf("\nAssert(%s) failed:\nfile: %s\nbase_file: %s\nln: %d", 
        exp, file, baseFile, line);
    /* FIXME: add abort here */
    while (1);
}
#endif
