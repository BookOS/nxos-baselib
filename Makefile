##
# Copyright (c) 2018-2022, NXOS Development Team
# SPDX-License-Identifier: Apache-2.0
# 
# Contains: Makefile for Source code
# 
# Change Logs:
# Date           Author            Notes
# 2022-1-31      JasonHu           Init
##

MAKE	:=make

#
# Cmds
#
.PHONY: all clean

all:
	@$(MAKE) -s -C src O=../build

clean:
	@$(MAKE) -s -C src clean O=../build
