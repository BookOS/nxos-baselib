/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: Error number
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2021-10-16     JasonHu           Init
 */

#ifndef __NXBASE_ERROR_H__
#define __NXBASE_ERROR_H__

#include <nxbase/defines.h>

enum NX_Error
{
    NX_EOK = 0, /* ok */
    NX_ERROR,   /* normal error */
    NX_EPERM,   /* no perimisson */
    NX_EINVAL,  /* invalid arg */
    NX_ETIMEOUT,/* timeout */
    NX_EFAULT,  /* execute fault */
    NX_ENORES,  /* no resource */
    NX_EAGAIN,  /* try again later */
    NX_EINTR,   /* interrupted */
    NX_ENOMEM,  /* no enough memory */
    NX_ENOFUNC, /* no function */
    NX_ENOSRCH, /* no search/found */
    NX_EIO,     /* mmio/portio */
    NX_EBUSY,   /* device or resource busy */
    NX_ERROR_NR
};
typedef enum NX_Error NX_Error;

NX_PRIVATE const char *__NX_ErrorString[] = 
{
    "ok",
    "normal error",
    "no perimisson",
    "invalid arg",
    "timeout",
    "execute fault",
    "no resource",
    "try again later",
    "interrupted",
    "no enough memory",
    "no function",
    "no search/found",
    "mmio/portio failed",
    "device or resource busy"
};

NX_INLINE const char *NX_ErrorToString(NX_Error err)
{
    if (err < NX_EOK || err >= NX_ERROR_NR)
    {
        return "unknown error";
    }
    return __NX_ErrorString[err];
}

#endif  /* __NXBASE_ERROR_H__ */
