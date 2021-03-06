/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: process api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-3-19      JasonHu           Init
 */

#ifndef __NXBASE_HUB_H__
#define __NXBASE_HUB_H__

#include <nxbase/xbook.h>

typedef void * NX_HubHandler;

typedef struct NX_Hub
{
    int hubData;
} NX_Hub;

#define NX_HUB_PARAM_NR 8
typedef struct NX_HubParam
{
    NX_U32 api;
    NX_Size args[NX_HUB_PARAM_NR];
} NX_HubParam;

NX_Error NX_HubRegister(const char *name, NX_Size maxClient);
NX_Error NX_HubUnregister(const char *name);
NX_Error NX_HubCallParam(NX_Hub *hub, NX_HubParam *param, NX_Size *retVal);
NX_Error NX_HubCallParamName(const char *name, NX_HubParam *param, NX_Size *retVal);
NX_Error NX_HubReturn(NX_Size retVal, NX_Error retErr);
NX_Error NX_HubPoll(NX_HubParam *param);
void *NX_HubTranslate(void *addr, NX_Size size);

NX_Error NX_HubDispatch(NX_HubParam *param, NX_HubHandler handlerTable[], NX_Size tableSize);
NX_Error NX_HubLoop(NX_HubHandler handlerTable[], NX_Size tableSize);

#endif  /* __NXBASE_HUB_H__ */
