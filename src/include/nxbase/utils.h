/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: nxbase utils
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-1       JasonHu           Init
 */

#ifndef __NXBASE_UTILS_H__
#define __NXBASE_UTILS_H__

#include <nxbase/xbook.h>

/* (utils) limits */
/* Minimum and maximum values a 'signed long int' can hold */
#ifdef NX_CPU_64BIT
#define NX_LONG_MAX		0x7fffffffffffffffL
#else
#define NX_LONG_MAX		0x7fffffffL
#endif

#define NX_LONG_MIN		(-NX_LONG_MAX - 1)

/* Maximum value an 'unsigned long int' can hold (Minimum is 0) */
#define NX_ULONG_MAX    (2UL * NX_LONG_MAX + 1)

/* (utils) va list */
typedef __builtin_va_list   NX_VarList;
/* prepare to access variable args */
#define NX_VarStart(v, l)		__builtin_va_start(v, l)
/* the caller will get the value of current argument */
#define NX_VarArg(v, l)		    __builtin_va_arg(v, l)
/* end for variable args */
#define NX_VarEnd(v)			__builtin_va_end(v)
/* copy variable args */
#define NX_VarCopy(d, s)		__builtin_va_copy(d, s)

/* (utils) print */
void NX_Printf(const char *fmt, ...);

/* (utils) memory */
void *NX_MemSet(void *dst, NX_U8 value, NX_Size sz);
void NX_MemCopy(void *dst, const void *src, NX_Size sz);
void *NX_MemZero(void *dst, NX_Size sz);
int NX_MemCompareN(const void *s1, const void *s2, NX_Size nBytes);

/* (utils) string */
char *NX_StrCopy(const char *dst, const char *src);
int NX_StrCmp(const char *a, const char *b);
int NX_StrLen(const char *str);
char *NX_StrCopyN(char * dest, const char * src, NX_Size n);
int NX_StrPrintfVarN(char *buf, int bufLen, const char *fmt, NX_VarList args);
int NX_StrPrintfN(char *buf, int buflen, const char *fmt, ...);
int NX_StrCmpN(const char * s1, const char * s2, NX_Size n);
char *NX_StrChr(const char *s, int c);
NX_Size NX_StrCopySafe(char *dest, const char *src, NX_Size len);
char *NX_StrChrReverse(const char *s, int c);
unsigned long NX_StrToUL(const char * nptr, char ** endptr, int base);
char * NX_StrCat(char * strDest , const char * strSrc);

/* (utils) ctype */
int NX_IsDigit(int c);
int NX_IsSpace(int c);
int NX_IsUpper(int c);
int NX_IsAlpha(int c);

#endif  /* __NXBASE_UTILS_H__ */
