/**
 * Copyright (c) 2018-2022, BookOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: entry for x86 arch
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-2-9       JasonHu           Init
 */

.code32
.text
.extern __NX_StartC
.global __NX_Start
.type __NX_Start, %function
.section .text.start
__NX_Start:
    xor %ebp,%ebp
    and $-16,%esp
    push %ebx
    call __NX_StartC
