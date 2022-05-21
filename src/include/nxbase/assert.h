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

#ifndef __NXBASE_ASSERT_H__
#define __NXBASE_ASSERT_H__

#include <nxbase/xbook.h>

#ifdef NX_DEBUG

void NX_AssertionFailure(char *exp, char *file, char *baseFile, int line);

#define NX_ASSERT(exp) \
    do \
    { \
        if (!(exp)) \
        { \
            NX_AssertionFailure(#exp, __FILE__, __BASE_FILE__, __LINE__); \
        } \
    } while(0)
#else
#define NX_ASSERT(exp)
#endif

#endif  /* __NXBASE_ASSERT_H__ */
