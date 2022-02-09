::
:: Copyright (c) 2018-2022, BookOS Development Team
:: SPDX-License-Identifier: Apache-2.0
:: 
:: Contains: windows bat scripts for nxbase lib environment
:: 
:: Change Logs:
:: Date           Author            Notes
:: 2022-1-31      JasonHu           Init
::

:: usage:
:: nxos.bat [arch]
:: example: nxos.bat            # x86
:: example: nxos.bat riscv64    # riscv64

@echo off

set def_arch=%1

if "%def_arch%" == "" (
    :: set default arch as x86
    set def_arch=x86
)

if "%def_arch%" == "x86" (
    set CROSS_COMPILE=x86_64-elf-
    set ARCH=x86
) else if "%def_arch%" == "riscv64" (
    set CROSS_COMPILE=riscv64-unknown-elf-
    set ARCH=riscv64
) else (
    echo unknown arch! %def_arch%
    goto end
)

echo Set environment for nxbase lib.
echo [CROSS COMPILE ] %CROSS_COMPILE%
echo [ARCH          ] %def_arch%
echo [NXBASE ARCH   ] %ARCH%

:end
@echo on
