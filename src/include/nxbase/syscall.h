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

#ifndef __NXBASE_CORE_SYSCALL__
#define __NXBASE_CORE_SYSCALL__

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

/* syscall api */
enum NX_SysApi
{
    NX_API_DebugLog = 1,     /* 1 */
    NX_API_ProcessExit,
    NX_API_ProcessCreate,    
};

#endif /* __NXBASE_CORE_SYSCALL__ */
