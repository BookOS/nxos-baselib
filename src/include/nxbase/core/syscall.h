/**
 * Copyright (c) 2018-2022, BookOS Development Team
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

#include <nxbase/types.h>

NX_UArch NX_Syscalls(NX_U32 api,
    NX_UArch a0,
    NX_UArch a1,
    NX_UArch a2,
    NX_UArch a3,
    NX_UArch a4,
    NX_UArch a5,
    NX_UArch a6);

#endif /* __NXBASE_CORE_SYSCALL__ */