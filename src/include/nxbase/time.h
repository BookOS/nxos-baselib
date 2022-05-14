/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: time api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-14     JasonHu           Init
 */

#ifndef __NXBASE_TIME_H__
#define __NXBASE_TIME_H__

#include <nxbase/xbook.h>

typedef struct {
    NX_U8 second;       /* [0-59] */
    NX_U8 minute;       /* [0-59] */
    NX_U8 hour;         /* [0-23] */
    NX_U8 weekDay;      /* [0-6] */
    NX_U32 day;         /* [1-31] */
    NX_U32 month;       /* [1-12] */
    NX_U32 year;        /* year */
    NX_U32 yearDay;     /* [0-366] */
} NX_Time;

NX_Error NX_TimeSet(NX_Time * time);
NX_Error NX_TimeGet(NX_Time * time);

#endif  /* __NXBASE_TIME_H__ */
