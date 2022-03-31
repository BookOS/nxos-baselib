/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: Compatiable functions
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-1       JasonHu           Init
 * 
 */

#include <nxbase/xbook.h>

/**
 * compatiable for gcc compiler with optimize
 */
NX_WEAK_SYM void * memset(void *dst, NX_U8 value, NX_Size sz)
{
    NX_U8 *dstPtr = (NX_U8 *)dst;
	while (sz > 0)
    {
		*dstPtr++ = value;
		--sz;
	}
	return dst;
}
