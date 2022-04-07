/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: hub system
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-7       JasonHu           Init
 */

#include <nxbase/syscall.h>
#include <nxbase/hub.h>

NX_Error NX_HubRegister(const char *name, NX_Addr callAddr, NX_Size maxClient)
{
    return NX_Syscall3(NX_API_HubRegister, name, callAddr, maxClient);
}

NX_Error NX_HubUnregister(const char *name)
{
    return NX_Syscall1(NX_API_HubUnregister, name);
}

NX_Error NX_HubCallParam(NX_Hub *hub, NX_HubParam *param, NX_Size *retVal)
{
    return NX_Syscall3(NX_API_HubCallParam, hub, param, retVal);
}

NX_Error NX_HubCallParamName(const char *name, NX_HubParam *param, NX_Size *retVal)
{
    return NX_Syscall3(NX_API_HubCallParamName, name, param, retVal);
}

NX_Error NX_HubReturn(NX_Size retVal)
{
    return NX_Syscall1(NX_API_HubReturn, retVal);
}
