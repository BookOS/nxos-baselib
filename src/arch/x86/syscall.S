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

.code32
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
	push %ebp
	push %edi
	push %esi
	push %edx
	push %ecx
	push %ebx

    /* save arg6 to user stack, reserve stack */
    subl $4, %esp

    /* 0x3c = 60 = 4 * 7 + 4 * 1 + 4 * 7 */
    mov 0x3c(%esp), %eax /* get arg6 */
    mov %eax, (%esp) /* save arg6 to stack */

    /* 0x20 = 32 = 4 * 7 + 4 * 1 */
	mov 0x20(%esp), %eax /* syscall api */
    mov 0x24(%esp), %ebx /* arg0 */
    mov 0x28(%esp), %ecx /* arg1 */
    mov 0x2c(%esp), %edx /* arg2 */
    mov 0x30(%esp), %esi /* arg3 */
    mov 0x34(%esp), %edi /* arg4 */
    mov 0x38(%esp), %ebp /* arg5 */
    
	int $0x80

    addl $4, %esp

	pop %ebx
	pop %ecx
	pop %edx
	pop %esi
    pop %edi
    pop %ebp
	ret
