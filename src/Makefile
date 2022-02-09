sinclude ../scripts/xbuild/env.mk

ARCH		?= x86

ifeq ($(ARCH),x86)
CC			:= $(CROSS_COMPILE)gcc -m32
AS			:= $(CROSS_COMPILE)gcc -m32
LD			:= $(CROSS_COMPILE)ld -m elf_i386

MCFLAGS		:= -march=i386
else
$(error unsupported arch!)
endif

X_CFLAGS	:= $(MCFLAGS) -fno-builtin -fno-stack-protector
X_CFLAGS	+= -nostdlib -nostdinc

X_ACFLAGS	+= $(MCFLAGS)

X_LDFLAGS 	:= -no-pie -nostartfile -n
X_LDFLAGS 	+= -nostdlib

X_INCDIRS	:= include

SRC			:= arch/$(ARCH)/
SRC			+= crt/

TARGET_TYPE	:= static
NAME		:= nxbase
