/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: process api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-3-19      JasonHu           Init
 * 2022-4-27      JasonHu           add set/get cwd
 */

#ifndef __NXBASE_PROCESS_H__
#define __NXBASE_PROCESS_H__

#include <nxbase/xbook.h>
#include <nxbase/vfs.h>

#define NX_PROC_FLAG_NOWAIT 0x00
#define NX_PROC_FLAG_WAIT 0x01

#define NX_SOLT_INVALID_VALUE -1

#define NX_SNAPSHOT_PROCESS 1
#define NX_SNAPSHOT_THREAD  2
#define NX_SNAPSHOT_MAX     3

#define NX_THREAD_NAME_LEN 32

#define NX_THREAD_STATE_INIT      0
#define NX_THREAD_STATE_READY     1
#define NX_THREAD_STATE_RUNNING   2
#define NX_THREAD_STATE_BLOCKED   3
#define NX_THREAD_STATE_EXIT      4

typedef int NX_Solt;

typedef struct NX_SnapshotThread
{
    NX_U32 usage;
    NX_U32 state;
    NX_U32 threadId;
    NX_U32 ownerProcessId;
    NX_U32 fixedPriority;
    NX_U32 priority;
    NX_U32 onCore;        /* thread on which core */
    NX_U32 coreAffinity;  /* thread would like to run on the core */
    NX_U32 flags;
    char name[NX_THREAD_NAME_LEN];
} NX_SnapshotThread;

typedef struct NX_SnapshotProcess
{
    NX_U32 usage;
    NX_U32 processId;
    NX_U32 threadCount;
    NX_U32 parentProcessId; 
    NX_U32 flags;
    char exePath[NX_VFS_MAX_PATH]; /* execute path */
} NX_SnapshotProcess;

void NX_ProcessExit(int exitCode);
NX_Error NX_ProcessLaunch(char *path, NX_U32 flags, int *retCode, char *cmd, char *env);

NX_Error NX_ProcessGetCwd(char * buf, NX_Size length);
NX_Error NX_ProcessSetCwd(char * buf);

NX_Error NX_SoltClose(NX_Solt solt);
NX_Solt NX_SnapshotCreate(NX_U32 snapshotType, NX_U32 flags, NX_Error * outErr);
NX_Error NX_SnapshotFirst(NX_Solt solt, void * object);
NX_Error NX_SnapshotNext(NX_Solt solt, void * object);

NX_Error NX_ThreadSleep(NX_UArch microseconds);

#endif  /* __NXBASE_PROCESS_H__ */
