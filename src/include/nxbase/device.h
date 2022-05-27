/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: device api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-27     JasonHu           Init
 */

#ifndef __NXBASE_DEVICE_H__
#define __NXBASE_DEVICE_H__

#include <nxbase/xbook.h>
#include <nxbase/process.h>

NX_Solt NX_DeviceOpen(const char * name, NX_U32 flags);
NX_Size NX_DeviceRead(NX_Solt solt, void *buf, NX_Offset off, NX_Size len);
NX_Size NX_DeviceWrite(NX_Solt solt, void *buf, NX_Offset off, NX_Size len);
NX_Error NX_DeviceControl(NX_Solt solt, NX_U32 cmd, void *arg);
#define NX_DeviceClose(solt) NX_SoltClose(solt)

#endif  /* __NXBASE_DEVICE_H__ */
