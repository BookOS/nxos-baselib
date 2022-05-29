/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: signal api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-29     JasonHu           Init
 */

#include <nxbase/syscall.h>
#include <nxbase/signal.h>

NX_Error NX_SignalSend(NX_U32 tid, NX_Signal signal, void * signalValue)
{
    return NX_Syscall3(NX_API_SignalSend, tid, signal, signalValue);
}
