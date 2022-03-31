/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: Memory tools
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-1       JasonHu           Init
 */

#include <nxbase/utils.h>

void *NX_MemSet(void *dst, NX_U8 value, NX_Size sz)
{
    NX_U8 *dstPtr = (NX_U8 *)dst;
	while (sz > 0)
    {
		*dstPtr++ = value;
		--sz;
	}
	return dst;
}

void NX_MemCopy(void *dst, const void *src, NX_Size sz)
{
    NX_U8 *dstPtr = (NX_U8 *)dst;
    NX_U8 *srcPtr = (NX_U8 *)src;
    while (sz-- > 0)
    {
        *dstPtr++ = *srcPtr++;
    }
}

void *NX_MemZero(void *dst, NX_Size sz)
{
    return NX_MemSet(dst, 0, sz);
}

int NX_MemCompareN(const void *s1, const void *s2, NX_Size nBytes)
{
	if ((s1 == 0) || (s2 == 0)) 
    {
		return (s1 - s2);
	}

	const char *p1 = (const char *)s1;
	const char *p2 = (const char *)s2;
	int i;
	for (i = 0; i < nBytes; i++,p1++,p2++)
    {
		if (*p1 != *p2)
        {
			return (*p1 - *p2);
		}
	}
	return 0;
}
