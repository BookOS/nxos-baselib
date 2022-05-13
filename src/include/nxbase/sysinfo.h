/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: sys info header
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-13     JasonHu           Init
 */

#ifndef __NXBASE_SYSINFO_H__
#define __NXBASE_SYSINFO_H__

#include <nxbase/xbook.h>

#define NX_CPUINFO_GET_CORES 1

#define NX_MAX_CPU  32

typedef struct NX_MemInfo
{
    NX_Size pageSize;
    NX_Size totalPage;
    NX_Size usedPage;
} NX_MemInfo;

typedef struct NX_CpuInfo
{
    NX_U32 usage[NX_MAX_CPU];
} NX_CpuInfo;

#endif  /* __NXBASE_SYSINFO_H__ */
