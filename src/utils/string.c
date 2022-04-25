/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: string tools 
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-1       JasonHu           Init
 */

#include <nxbase/utils.h>

char *NX_StrCopy(const char *dst, const char *src)
{
    char *dstPtr = (char *) dst;
    while ((*dstPtr++ = *src++));

    return (char *)dst;
}

/*
 * Writes exactly n bytes, copying from source or adding nulls
 */
char *NX_StrCopyN(char * dest, const char * src, NX_Size n)
{
	char * tmp = dest;

	while (n)
	{
		if ((*tmp = *src) != 0)
			src++;
		tmp++;
		n--;
	}
	return dest;
}

int NX_StrCmp(const char *a, const char *b)
{
    while (*a && *a == *b)
    {
        a++;
        b++;
    }

    return (*a - *b);
}

int NX_StrCmpN(const char * s1, const char * s2, NX_Size n)
{
	int __res = 0;

	while (n)
	{
		if ((__res = *s1 - *s2++) != 0 || !*s1++)
        {
			break;
        }
		n--;
	}
	return __res;
}

int NX_StrLen(const char *str)
{
    const char *p = str;
    while(*p++);
    return (p - str - 1);
}

/*
 * A variant of NX_StrCopy that truncates the result to fit in the destination buffer
 */
NX_Size NX_StrCopySafe(char *dest, const char *src, NX_Size len)
{
	NX_Size n;
	NX_Size ret = NX_StrLen(src);

	if (len)
	{
		n = (ret >= len) ? len - 1 : ret;
		NX_MemCopy(dest, (void *)src, n);
		dest[n] = '\0';
	}
	return ret;
}

/*
 * Finds the last occurrence of a byte in a string
 */
char *NX_StrChrReverse(const char *s, int c)
{
	const char * p = s + NX_StrLen(s);

	do
    {
        if (*p == (char)c)
        {
		   return (char *)p;
        }
	}
    while (--p >= s);

	return NX_NULL;
}

/*
 * Finds the first occurrence of a byte in a string
 */
char *NX_StrChr(const char *s, int c)
{
	for (; *s != (char)c; ++s)
    {
		if (*s == '\0')
        {
			return NX_NULL;
        }
    }
	return (char *)s;
}


/*
 * Convert a string to an unsigned long integer.
 *
 * Ignores 'locale' stuff.  Assumes that the upper and lower case
 * alphabets and digits are each contiguous.
 */
unsigned long NX_StrToUL(const char * nptr, char ** endptr, int base)
{
	const char * s;
	unsigned long acc, cutoff;
	int c;
	int neg, any, cutlim;

	/*
	 * See strtol for comments as to the logic used.
	 */
	s = nptr;
	do {
		c = (unsigned char) *s++;
	} while (NX_IsSpace(c));

	if (c == '-')
	{
		neg = 1;
		c = *s++;
	}
	else
	{
		neg = 0;
		if (c == '+')
			c = *s++;
	}

	if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X'))
	{
		c = s[1];
		s += 2;
		base = 16;
	}

	if (base == 0)
		base = c == '0' ? 8 : 10;

	cutoff = NX_ULONG_MAX / (unsigned long) base;
	cutlim = NX_ULONG_MAX % (unsigned long) base;

	for (acc = 0, any = 0;; c = (unsigned char) *s++)
	{
		if (NX_IsDigit(c))
			c -= '0';
		else if (NX_IsAlpha(c))
			c -= NX_IsUpper(c) ? 'A' - 10 : 'a' - 10;
		else
			break;

		if (c >= base)
			break;

		if (any < 0)
			continue;

		if (acc > cutoff || (acc == cutoff && c > cutlim))
		{
			any = -1;
			acc = NX_ULONG_MAX;
		}
		else
		{
			any = 1;
			acc *= (unsigned long) base;
			acc += c;
		}
	}

	if (neg && any > 0)
		acc = -acc;

	if (endptr != 0)
		*endptr = (char *) (any ? s - 1 : nptr);

	return (acc);
}

char * NX_StrCat(char * strDest , const char * strSrc)
{
    char * address = strDest;
    while (*strDest)
    {
        strDest++;
    }
    while ((*strDest++ = *strSrc++));
    return (char* )address;
}
