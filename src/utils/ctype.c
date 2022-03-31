/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: ctype for nxos
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2021-10-3      JasonHu           Init
 */

#include <nxbase/utils.h>

int NX_IsDigit(int c)
{
	return ((unsigned)c - '0') < 10;
}

int NX_IsSpace(int c)
{
	return (c == ' ') || ((unsigned)c - '\t' < 5);
}

int NX_IsUpper(int c)
{
	return ((unsigned)c - 'A') < 26;
}

int NX_IsAlpha(int c)
{
	return (((unsigned)c | 32) - 'a') < 26;
}