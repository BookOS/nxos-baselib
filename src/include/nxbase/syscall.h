/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: syscall header
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-2-9       JasonHu           Init
 */

#ifndef __NXBASE_SYSCALL_H__
#define __NXBASE_SYSCALL_H__

#include <nxbase/xbook.h>

#define __NX_SYSCALL_ARG(X) ((NX_UArch)(X))

NX_UArch NX_Syscalls(NX_U32 api,
    NX_UArch a0,
    NX_UArch a1,
    NX_UArch a2,
    NX_UArch a3,
    NX_UArch a4,
    NX_UArch a5,
    NX_UArch a6);

#define __NX_Syscall0(n) NX_Syscalls(n, 0, 0, 0, 0, 0, 0, 0)
#define __NX_Syscall1(n, a) NX_Syscalls(n, __NX_SYSCALL_ARG(a), 0, 0, 0, 0, 0, 0)
#define __NX_Syscall2(n, a, b) NX_Syscalls(n, __NX_SYSCALL_ARG(a), __NX_SYSCALL_ARG(b), 0, 0, 0, 0, 0)
#define __NX_Syscall3(n, a, b, c) NX_Syscalls(n, __NX_SYSCALL_ARG(a), __NX_SYSCALL_ARG(b), __NX_SYSCALL_ARG(c), 0, 0, 0, 0)
#define __NX_Syscall4(n, a, b, c, d) NX_Syscalls(n, __NX_SYSCALL_ARG(a), __NX_SYSCALL_ARG(b), __NX_SYSCALL_ARG(c), __NX_SYSCALL_ARG(d), 0, 0, 0)
#define __NX_Syscall5(n, a, b, c, d, e) NX_Syscalls(n, __NX_SYSCALL_ARG(a), __NX_SYSCALL_ARG(b), __NX_SYSCALL_ARG(c), __NX_SYSCALL_ARG(d), __NX_SYSCALL_ARG(e), 0, 0)
#define __NX_Syscall6(n, a, b, c, d, e, f) NX_Syscalls(n, __NX_SYSCALL_ARG(a), __NX_SYSCALL_ARG(b), __NX_SYSCALL_ARG(c), __NX_SYSCALL_ARG(d), __NX_SYSCALL_ARG(e), __NX_SYSCALL_ARG(f), 0)
#define __NX_Syscall7(n, a, b, c, d, e, f, g) NX_Syscalls(n, __NX_SYSCALL_ARG(a), __NX_SYSCALL_ARG(b), __NX_SYSCALL_ARG(c), __NX_SYSCALL_ARG(d), __NX_SYSCALL_ARG(e), __NX_SYSCALL_ARG(f), __NX_SYSCALL_ARG(g))

#define __NX_SYSCALL_NARGS_X(a, b, c, d, e, f, g, h, n, ...) n
#define __NX_SYSCALL_NARGS(...) __NX_SYSCALL_NARGS_X(__VA_ARGS__, 7, 6, 5, 4, 3, 2, 1, 0, )
#define __NX_SYSCALL_CONCAT_X(a, b) a##b
#define __NX_SYSCALL_CONCAT(a, b) __NX_SYSCALL_CONCAT_X(a, b)
#define __NX_SYSCALL_DISP(b, ...)                        \
    __NX_SYSCALL_CONCAT(b, __NX_SYSCALL_NARGS(__VA_ARGS__)) \
    (__VA_ARGS__)

#define __NX_Syscall(...) __NX_SYSCALL_DISP(__NX_Syscall, __VA_ARGS__)
#define NX_Syscall(...) __NX_Syscall(__VA_ARGS__)

#define NX_Syscall0(n) __NX_Syscall0(n)
#define NX_Syscall1(n, a) __NX_Syscall1(n, a)
#define NX_Syscall2(n, a, b) __NX_Syscall2(n, a, b)
#define NX_Syscall3(n, a, b, c) __NX_Syscall3(n, a, b, c)
#define NX_Syscall4(n, a, b, c, d) __NX_Syscall4(n, a, b, c, d)
#define NX_Syscall5(n, a, b, c, d, e) __NX_Syscall5(n, a, b, c, d, e)
#define NX_Syscall6(n, a, b, c, d, e, f) __NX_Syscall6(n, a, b, c, d, e, f)
#define NX_Syscall7(n, a, b, c, d, e, f, g) __NX_Syscall7(n, a, b, c, d, e, f, g)

/* syscall api */
enum NX_SysApi
{
    NX_API_DebugLog = 1,     /* 1 */
    NX_API_ProcessExit,
    NX_API_ProcessLaunch,    
    NX_API_VfsMount,
    NX_API_VfsUnmount,          /* 5 */
    NX_API_VfsSync,
    NX_API_VfsOpen,
    NX_API_VfsClose,
    NX_API_VfsRead,
    NX_API_VfsWrite,            /* 10 */
    NX_API_VfsFileSeek,
    NX_API_VfsFileSync,
    NX_API_VfsFileChmod,
    NX_API_VfsFileStat,
    NX_API_VfsOpenDir,          /* 15 */
    NX_API_VfsCloseDir,
    NX_API_VfsReadDir,
    NX_API_VfsRewindDir,
    NX_API_VfsMakeDir,
    NX_API_VfsRemoveDir,        /* 20 */
    NX_API_VfsRename,
    NX_API_VfsUnlink,
    NX_API_VfsAccess,
    NX_API_VfsChmod,
    NX_API_VfsStat,             /* 25 */
    NX_API_HubRegister,
    NX_API_HubUnregister,
    NX_API_HubCallParam,
    NX_API_HubCallParamName,
    NX_API_HubReturn,           /* 30 */
    NX_API_HubPoll,
    NX_API_HubTranslate,
    NX_API_VfsIoctl,
    NX_API_MemMap,
    NX_API_MemUnmap,            /* 35 */
    NX_API_MemHeap,
    NX_API_ProcessGetCwd,
    NX_API_ProcessSetCwd,
    NX_API_SoltClose,
    NX_API_SnapshotCreate,      /* 40 */
    NX_API_SnapshotFirst,
    NX_API_SnapshotNext,
    NX_API_ThreadSleep,
    NX_API_ClockGetMillisecond,
    NX_API_TimeSet,
    NX_API_TimeGet,
    NX_API_ThreadCreate,
    NX_API_ThreadExit,
    NX_API_ThreadSuspend,
    NX_API_ThreadResume,        /* 50 */
    NX_API_ThreadWait,
    NX_API_ThreadTerminate,
    NX_API_ThreadGetId,
    NX_API_ThreadGetCurrentId,
    NX_API_ThreadGetCurrent,    /* 55 */
    NX_API_ThreadGetProcessId,
    NX_API_SemaphoreCreate,
    NX_API_SemaphoreDestroy,
    NX_API_SemaphoreWait,
    NX_API_SemaphoreTryWait,    /* 60 */
    NX_API_SemaphoreSignal,
    NX_API_SemaphoreSignalAll,
    NX_API_SemaphoreGetValue,
    NX_API_MutexCreate,
    NX_API_MutexDestroy,        /* 65 */
    NX_API_MutexAcquire,
    NX_API_MutexTryAcquire,
    NX_API_MutexRelease,
    NX_API_MutexAcquirable,
    NX_API_DeviceOpen,          /* 70 */
    NX_API_DeviceRead,
    NX_API_DeviceWrite,
    NX_API_DeviceControl,
};

#endif /* __NXBASE_SYSCALL_H__ */
