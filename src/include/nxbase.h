/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: next xbook base lib header file, include all header files.
 *           This file should never include in lib, only for user.
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-2-9       JasonHu           Init
 */

#ifndef __NXBASE_ALL_H__
#define __NXBASE_ALL_H__

#include <nxbase/xbook.h>

/* core header */
#include <nxbase/syscall.h>
#include <nxbase/process.h>
#include <nxbase/debug.h>
#include <nxbase/crt.h>

/* utils header */
#include <nxbase/utils.h>

/* module header */
#include <nxbase/vfs.h>
#include <nxbase/hub.h>
#include <nxbase/mman.h>
#include <nxbase/clock.h>

#endif /* __NXBASE_ALL_H__ */
