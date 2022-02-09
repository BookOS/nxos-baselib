/**
 * Copyright (c) 2018-2022, BookOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: I386 registers 
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2021-9-29      JasonHu           Init
 */

#ifndef __XBOOK_TYPES__
#define __XBOOK_TYPES__

typedef unsigned long long  NX_U64;
typedef signed long long    NX_I64;
typedef unsigned int        NX_U32;
typedef signed int          NX_I32;
typedef unsigned short      NX_U16;
typedef signed short        NX_I16;
typedef unsigned char       NX_U8;
typedef signed char         NX_I8;

typedef unsigned long       NX_UArch;
typedef signed long         NX_IArch;

typedef unsigned long       NX_Addr;

typedef unsigned long       NX_Size;
typedef signed long         NX_SSize;

typedef long NX_PtrDiff;
typedef long NX_Offset;

enum NX_Bool
{
    NX_False = 0,
    NX_True,
};
typedef enum NX_Bool NX_Bool;

#endif  /* __XBOOK_TYPES__ */
