sinclude ../scripts/xbuild/env.mk

ARCH		?= x86

ifeq ($(ARCH),x86) # x86

CC			:= $(CROSS_COMPILE)gcc -m32
AS			:= $(CROSS_COMPILE)gcc -m32
LD			:= $(CROSS_COMPILE)ld -m elf_i386

MCFLAGS		:= -march=i386
else ifeq ($(ARCH),riscv64) # riscv64

MCFLAGS		:= -march=rv64imafdc -mabi=lp64d -mcmodel=medany -DNX_CPU_64BIT
else
$(error unsupported arch!)
endif

X_CFLAGS	:= $(MCFLAGS) -fno-builtin -fno-stack-protector
X_CFLAGS	+= -nostdlib -nostdinc -Wall -O3 -ffunction-sections -fdata-sections -ffreestanding -std=gnu99

X_ACFLAGS	+= $(MCFLAGS) -Wall -O3 -ffunction-sections -fdata-sections -ffreestanding -std=gnu99

X_LDFLAGS 	:= -no-pie -nostartfile -n
X_LDFLAGS 	+= -nostdlib

X_INCDIRS	:= include

SRC			:= arch/$(ARCH)/
SRC			+= crt/
SRC			+= process/
SRC			+= debug/
SRC			+= utils/
SRC			+= vfs/
SRC			+= ipc/
SRC			+= mman/
SRC			+= time/

TARGET_TYPE	:= static
NAME		:= nxbase
