/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: thread local storage
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-20     JasonHu           Init
 */

#include <nxbase/xbook.h>

void * __NX_TlsGetArea(void)
{
    void * tlsArea;
	NX_CASM ("mv %0, tp" : "=r"(tlsArea));
	return tlsArea;
}
