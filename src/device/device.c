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

#include <nxbase/syscall.h>
#include <nxbase/device.h>

NX_Solt NX_DeviceOpen(const char * name, NX_U32 flags)
{
    NX_Solt solt = NX_SOLT_INVALID_VALUE;
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall3(NX_API_DeviceOpen, name, flags, &solt)));
    return solt;
}

NX_Size NX_DeviceRead(NX_Solt solt, void *buf, NX_Offset off, NX_Size len)
{
    NX_Error err;
    NX_Size outLen = 0;

    NX_ErrorSet((err = NX_Syscall5(NX_API_DeviceRead, solt, buf, off, len, &outLen)));
    return outLen;
}

NX_Size NX_DeviceWrite(NX_Solt solt, void *buf, NX_Offset off, NX_Size len)
{
    NX_Error err;
    NX_Size outLen = 0;

    NX_ErrorSet((err = NX_Syscall5(NX_API_DeviceWrite, solt, buf, off, len, &outLen)));
    return outLen;
}

NX_Error NX_DeviceControl(NX_Solt solt, NX_U32 cmd, void *arg)
{
    NX_Error err;

    NX_ErrorSet((err = NX_Syscall3(NX_API_DeviceControl, solt, cmd, arg)));
    return err;
}
