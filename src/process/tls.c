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

#include <nxbase/process.h>

typedef struct NX_TlsArea
{
    struct NX_TlsArea * tlsAreaSelf;    /* tls area self */
    NX_Error error; /* error in tls, save current thread error number */
    void * extensionData; /* tls extension data */
    /* tls data area */
    NX_U8 bitmap[NX_TLS_MAX_NR / 8]; /* bitmap for tls index allocate */
    void * tlsData[NX_TLS_MAX_NR];
} NX_TlsArea;

NX_IMPORT void * __NX_TlsGetArea(void);

int NX_TLsAlloc(void)
{
    NX_TlsArea * tlsArea = (void *)__NX_TlsGetArea();
    int i;
    for (i = 0; i < NX_TLS_MAX_NR; i++)
    {
        if (!(tlsArea->bitmap[i / 8] & (1 << (i % 8))))
        {
            tlsArea->bitmap[i / 8] |= (1 << (i % 8));
            return i;
        }
    }
    return -1;
}

NX_Error NX_TLsFree(int index)
{
    NX_TlsArea * tlsArea = (void *)__NX_TlsGetArea();

    if (index >= NX_TLS_MAX_NR || index < 0)
    {
        return NX_EINVAL;
    }
    tlsArea->bitmap[index / 8] &= ~(1 << (index % 8));
    tlsArea->tlsData[index] = NX_NULL;
    return NX_EOK;
}

NX_Error NX_TLsSetValue(int index, void * value)
{
    NX_TlsArea * tlsArea = (void *)__NX_TlsGetArea();

    if (index >= NX_TLS_MAX_NR || index < 0)
    {
        return NX_EINVAL;
    }
    tlsArea->tlsData[index] = value;
    return NX_EOK;
}

void * NX_TLsGetValue(int index)
{
    NX_TlsArea * tlsArea = (void *)__NX_TlsGetArea();

    if (index >= NX_TLS_MAX_NR || index < 0)
    {
        return NX_NULL;
    }
    return tlsArea->tlsData[index];
}

/**
 * error saved in tls, each thread get error from tls
 */
NX_Error * NX_ErrorGetLocation(void)
{
    NX_TlsArea * tlsArea = (void *)__NX_TlsGetArea();
    return &tlsArea->error;
}

void NX_TlsSetExtension(void * data)
{
    NX_TlsArea * tlsArea = (void *)__NX_TlsGetArea();
    tlsArea->extensionData = data;
}

void * NX_TlsGetExtension(void)
{
    NX_TlsArea * tlsArea = (void *)__NX_TlsGetArea();
    return tlsArea->extensionData;
}
