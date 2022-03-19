/**
 * Copyright (c) 2018-2022, NXOS Development Team
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

/* __NX_Start(void *args); */
.global __NX_Start
.type __NX_Start, %function
.section .text.start
__NX_Start:
    call __NX_StartC
