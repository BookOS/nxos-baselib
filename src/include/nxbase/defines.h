/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: define for nxbase
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-2-9       JasonHu           Init
 */

#ifndef __NXBASE_DEFINES_H__
#define __NXBASE_DEFINES_H__

#define NX_NULL ((void *) 0)

/**
 * Private variable or function 
 */
#define NX_PRIVATE static

/**
 * Operating system interface
 */
#define NX_INTERFACE 

/**
 * Import variable or function 
 */
#define NX_IMPORT extern

/**
 * Export variable or function
 * TODO: add to link module 
 */
#define NX_EXPORT

/**
 * Inline function 
 * 
 */
#define NX_INLINE  static inline

/**
 * Inline assembly 
 */
#define NX_CASM    __asm__ __volatile__

/**
 * Align
 */
#define NX_ALIGN_UP(x, y) ((x + (y - 1)) & (~(y - 1)))
#define NX_ALIGN_DOWN(x, y) ((x) & ~((y) - 1))

/**
 * Offset of struct
 */
#define NX_OFFSET_OF_STRUCT(type, member) ((NX_USize) &((type *)0)->member)

/**
 * Ptr of struct base addr 
 */
#define NX_PTR_OF_STRUCT(ptr, type, member) ({ \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - NX_OFFSET_OF_STRUCT(type,member) ); \
})

#define NX_TYPE_CAST(t, exp) ((t)(exp))
#define NX_ARRAY_CAST(p, size) (((char(*)[size])(p)))

#define NX_MIN(x, y) ({typeof(x) _x = (x);typeof(y) _y = (y);(void)(&_x == &_y);_x < _y ? _x : _y; })

#define NX_KB   1024
#define NX_MB   (NX_KB * 1024)
#define NX_GB   (NX_MB * 1024)
#define NX_TB   (NX_GB * 1024)

/**
 * Compile Align
 */
#define NX_CALIGN(size) __attribute__((aligned(size)))

/**
 * Make sure no compile optimization
 */
#define NX_VOLATILE __volatile__ 

#define NX_DIV_ROUND_UP(x, step) (((x) + (step) - 1) / (step))
#define NX_DIV_ROUND_DOWN(x, step) ((x) / (step))

/**
 * calc array element count
 */
#define NX_ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))

/**
 * weak symble
 */
#define NX_WEAK_SYM __attribute__((weak))

#define NX_SECTION(x)          __attribute__((section(x)))
#define NX_UNUSED              __attribute__((unused))
#define NX_USED                __attribute__((used))
#define NX_ALIGN(n)            __attribute__((aligned(n)))
#define NX_PACKED              __attribute__((packed))

#endif  /* __NXBASE_DEFINES_H__ */
