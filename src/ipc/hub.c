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

NX_Error NX_HubRegister(const char *name, NX_Size maxClient)
{
    return NX_Syscall2(NX_API_HubRegister, name, maxClient);
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

NX_Error NX_HubReturn(NX_Size retVal, NX_Error retErr)
{
    return NX_Syscall2(NX_API_HubReturn, retVal, retErr);
}

NX_Error NX_HubPoll(NX_HubParam *param)
{
    return NX_Syscall1(NX_API_HubPoll, param);
}

typedef NX_UArch (*NX_HubHandlerWithArg) (NX_UArch, NX_UArch, NX_UArch, NX_UArch, NX_UArch, NX_UArch, NX_UArch, NX_UArch);

NX_PRIVATE NX_HubHandler NX_HubGetHandler(NX_U32 api, NX_HubHandler handlerTable[], NX_Size tableSize)
{
    NX_HubHandler handler = NX_NULL;

    if (api < tableSize)
    {
        handler = handlerTable[api];
    }
    return handler;
}

NX_Error NX_HubDispatch(NX_HubParam *param, NX_HubHandler handlerTable[], NX_Size tableSize)
{
    NX_Error errVal = NX_EOK;
    NX_UArch retVal = 0;
    NX_HubHandlerWithArg handler;

    if (!param || !handlerTable || !tableSize)
    {
        return NX_EINVAL;
    }

    handler = (NX_HubHandlerWithArg)NX_HubGetHandler(param->api, handlerTable, tableSize);
    if (handler == NX_NULL)
    {
        errVal = NX_ENORES;
    }
    else
    {
        retVal = handler(param->args[0], param->args[1], param->args[2], param->args[3],
                         param->args[4], param->args[5], param->args[6], param->args[7]);
    }

    return NX_HubReturn(retVal, errVal);
}

NX_Error NX_HubLoop(NX_HubHandler handlerTable[], NX_Size tableSize)
{
    NX_Error err;
    NX_HubParam param;
    while (1)
    {
        err = NX_HubPoll(&param);
        if (err == NX_ENORES)
        {
            return NX_ENORES;
        }
        else if (err == NX_EOK)
        {
            err = NX_HubDispatch(&param, handlerTable, tableSize);
            if (err != NX_EOK)
            {
                return err;
            }
        }
    }
}
