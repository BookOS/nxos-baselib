/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: virtual file system
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-1       JasonHu           Init
 */

#include <nxbase/vfs.h>
#include <nxbase/syscall.h>

NX_Error NX_VfsMount(const char * dev, const char * dir, const char * fsname, NX_U32 flags)
{
    return NX_Syscall4(NX_API_VfsMount, dev, dir, fsname, flags);
}

NX_Error NX_VfsUnmount(const char * path)
{
    return NX_Syscall1(NX_API_VfsUnmount, path);
}

NX_Error NX_VfsSync(void)
{
    return NX_Syscall(NX_API_VfsSync);
}

int NX_VfsOpen(const char * path, NX_U32 flags, NX_U32 mode, NX_Error *outErr)
{
    return NX_Syscall4(NX_API_VfsOpen, path, flags, mode, outErr);
}

NX_Error NX_VfsClose(int fd)
{
    return NX_Syscall1(NX_API_VfsClose, fd);
}

NX_U64 NX_VfsRead(int fd, void * buf, NX_U64 len, NX_Error *outErr)
{
    return NX_Syscall4(NX_API_VfsRead, fd, buf, len, outErr);
}

NX_U64 NX_VfsWrite(int fd, void * buf, NX_U64 len, NX_Error *outErr)
{
    return NX_Syscall4(NX_API_VfsWrite, fd, buf, len, outErr);
}

NX_Error NX_VfsIoctl(int fd, NX_U32 cmd, void *arg)
{
   return NX_Syscall3(NX_API_VfsIoctl, fd, cmd, arg);
}

NX_I64 NX_VfsFileSeek(int fd, NX_I64 off, int whence, NX_Error *outErr)
{
    return NX_Syscall4(NX_API_VfsFileSeek, fd, off, whence, outErr);
}

NX_Error NX_VfsFileSync(int fd)
{
    return NX_Syscall(NX_API_VfsFileSync, fd);
}

NX_Error NX_VfsFileChmod(int fd, NX_U32 mode)
{
    return NX_Syscall2(NX_API_VfsFileChmod, fd, mode);
}

NX_Error NX_VfsFileStat(int fd, NX_VfsStatInfo * st)
{
    return NX_Syscall2(NX_API_VfsFileStat, fd, st);
}

int NX_VfsOpenDir(const char * name, NX_Error *outErr)
{
    return NX_Syscall2(NX_API_VfsOpenDir, name, outErr);
}

NX_Error NX_VfsCloseDir(int fd)
{
    return NX_Syscall1(NX_API_VfsCloseDir, fd);
}

NX_Error NX_VfsReadDir(int fd, NX_VfsDirent * dir)
{
    return NX_Syscall2(NX_API_VfsReadDir, fd, dir);
}

NX_Error NX_VfsRewindDir(int fd)
{
    return NX_Syscall1(NX_API_VfsRewindDir, fd);
}

NX_Error NX_VfsMakeDir(const char * path, NX_U32 mode)
{
    return NX_Syscall2(NX_API_VfsMakeDir, path, mode);
}

NX_Error NX_VfsRemoveDir(const char * path)
{
    return NX_Syscall1(NX_API_VfsRemoveDir, path);
}

NX_Error NX_VfsRename(const char * src, const char * dst)
{
    return NX_Syscall2(NX_API_VfsRename, src, dst);
}

NX_Error NX_VfsUnlink(const char * path)
{
    return NX_Syscall1(NX_API_VfsUnlink, path);
}

NX_Error NX_VfsAccess(const char * path, NX_U32 mode)
{
    return NX_Syscall2(NX_API_VfsAccess, path, mode);
}

NX_Error NX_VfsChmod(const char * path, NX_U32 mode)
{
    return NX_Syscall1(NX_API_VfsChmod, path);
}

NX_Error NX_VfsStat(const char * path, NX_VfsStatInfo * st)
{
    return NX_Syscall2(NX_API_VfsStat, path, st);
}
