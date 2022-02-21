/**
 * Copyright (c) 2018-2022, BookOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: syscall for x86 arch
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-2-9       JasonHu           Init
 */

.text

/* 
NX_UArch NX_Syscalls(NX_U32 api,
    NX_UArch a0,
    NX_UArch a1,
    NX_UArch a2,
    NX_UArch a3,
    NX_UArch a4,
    NX_UArch a5,
    NX_UArch a6);
*/
.global NX_Syscalls
NX_Syscalls:
	mv t0, a0
    mv a0, a1
    mv a1, a2
    mv a2, a3
    mv a3, a4
    mv a4, a5
    mv a5, a6
    mv a6, a7
    mv a7, t0
    scall
    ret
