/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: memory management brk api
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-05-22     JasonHu           Init
 */

#include <nxbase/mman.h>
#include <nxbase/syscall.h>

/* This must be initialized data because commons can't have aliases.  */
NX_PRIVATE void * __curbrk = NX_NULL;

int NX_PosixBrk(void * addr)
{
    NX_Error err = NX_EOK;
  	void * newbrk;

	__curbrk = newbrk = (void *) NX_MemHeap(addr, &err);
	
    if (newbrk < addr || err != NX_EOK)
    {
      	return -1;
    }

 	return 0;
}

void * NX_PosixSbrk(int increment)
{
  	void * oldbrk;

	if (__curbrk == NX_NULL)
    {
    	if (NX_PosixBrk(0) < 0)
        {
      		return (void *) -1;
        }
    }
	
  	if (increment == 0)
    {
    	return __curbrk;
    }

	/* Get brk */
  	oldbrk = __curbrk;

	/* If brk not right or __brk failed, return -1. */
  	if ((increment > 0 ?
    	((NX_UArch) oldbrk + (NX_UArch) increment < (NX_UArch) oldbrk) :
       	((NX_IArch)oldbrk < -((NX_IArch)increment))) ||
      	NX_PosixBrk((void *)((NX_IArch)oldbrk + (NX_IArch)increment)) < 0)
    {
    	return (void *) -1;
    }

	return oldbrk;
}
