#!/bin/bash

##
# Copyright (c) 2018-2022, BookOS Development Team
# SPDX-License-Identifier: Apache-2.0
# 
# Contains: shell scripts for nxbase lib environment
# 
# Change Logs:
# Date           Author            Notes
# 2022-1-31      JasonHu           Init
##

# usage:
# source nxos.sh [arch]
# example: source nxos.sh           # x86
# example: source nxos.sh riscv64   # riscv64

# supported targe list
supported_arch="x86 riscv64"

def_arch="unknown" 

# find arch in arch list
if [ -z $1 ]
then
    def_arch="x86" # default arch is x86
else
    for arch in $supported_arch
    do
        if [ $arch = $1 ]
        then
            def_arch=$arch
            break
        fi
    done
fi

# set env
case $def_arch in 
    "x86")
        export CROSS_COMPILE=    
        export ARCH=x86
        ;;
    "riscv64")
        export CROSS_COMPILE=$NXOS_ROOT_DIR/tools/gcc/riscv64-unknown-elf-gcc/bin
        export ARCH=riscv64
        ;;
    *)  echo "unknown arch! " $def_arch
        return 1
esac

echo "Set environment for nxbase lib."
echo [CROSS COMPILE ] $CROSS_COMPILE
echo [ARCH          ] $def_arch
echo [NXBASE ARCH   ] $ARCH
