/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: c runtime
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-26      JasonHu           Init
 */

#ifndef __NXBASE_CRT_H__
#define __NXBASE_CRT_H__

int NX_EnvToArray(char * buf, char * argArray[], int maxArgs);
int NX_CmdToArray(char * buf, char * argArray[], int maxArgs);
int NX_EnvToBuf(char * buf, int bufLen, char * argArray[]);
int NX_CmdToBuf(char * buf, int bufLen, char * argArray[]);

#endif  /* __NXBASE_CRT_H__ */
