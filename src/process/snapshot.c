/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: solt close
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-03     JasonHu           Init
 */

#include <nxbase/syscall.h>
#include <nxbase/process.h>

NX_Solt NX_SnapshotCreate(NX_U32 snapshotType, NX_U32 flags, NX_Error * outErr)
{
    return NX_Syscall3(NX_API_SnapshotCreate, snapshotType, flags, outErr);
}

NX_Error NX_SnapshotFirst(NX_Solt solt, void * object)
{
    return NX_Syscall2(NX_API_SnapshotFirst, solt, object);
}

NX_Error NX_SnapshotNext(NX_Solt solt, void * object)
{
    return NX_Syscall2(NX_API_SnapshotNext, solt, object);
}
