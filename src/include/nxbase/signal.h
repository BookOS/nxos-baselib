/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: signal api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-30     JasonHu           Init
 */

#ifndef __NXBASE_SIGNAL_H__
#define __NXBASE_SIGNAL_H__

#include <nxbase/xbook.h>

typedef NX_U32 NX_Signal;

NX_Error NX_SignalSend(NX_U32 tid, NX_Signal signal, void * signalValue);

#endif  /* __NXBASE_SIGNAL_H__ */
