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

#ifndef __NXBASE___
#define __NXBASE___

#include <nxbase/xbook.h>

#define NX_VFS_MAX_PATH		    (1024)
#define NX_VFS_MAX_NAME		    (256)

#define NX_VFS_O_RDONLY			(1 << 0)
#define NX_VFS_O_WRONLY			(1 << 1)
#define NX_VFS_O_RDWR			(NX_VFS_O_RDONLY | NX_VFS_O_WRONLY)
#define NX_VFS_O_ACCMODE		(NX_VFS_O_RDWR)

#define NX_VFS_O_CREAT			(1 << 8)
#define NX_VFS_O_EXCL			(1 << 9)
#define NX_VFS_O_NOCTTY			(1 << 10)
#define NX_VFS_O_TRUNC			(1 << 11)
#define NX_VFS_O_APPEND			(1 << 12)
#define NX_VFS_O_DSYNC		    (1 << 13)
#define NX_VFS_O_NONBLOCK		(1 << 14)
#define NX_VFS_O_SYNC			(1 << 15)

#define NX_VFS_S_IXOTH			(1 << 0)
#define NX_VFS_S_IWOTH			(1 << 1)
#define NX_VFS_S_IROTH			(1 << 2)
#define NX_VFS_S_IRWXO			(NX_VFS_S_IROTH | NX_VFS_S_IWOTH | NX_VFS_S_IXOTH)

#define NX_VFS_S_IXGRP			(1 << 3)
#define NX_VFS_S_IWGRP			(1 << 4)
#define NX_VFS_S_IRGRP			(1 << 5)
#define NX_VFS_S_IRWXG			(NX_VFS_S_IRGRP | NX_VFS_S_IWGRP | NX_VFS_S_IXGRP)

#define NX_VFS_S_IXUSR			(1 << 6)
#define NX_VFS_S_IWUSR			(1 << 7)
#define NX_VFS_S_IRUSR			(1 << 8)
#define NX_VFS_S_IRWXU			(NX_VFS_S_IRUSR | NX_VFS_S_IWUSR | NX_VFS_S_IXUSR)

#define	NX_VFS_S_IFDIR			(1 << 16)
#define	NX_VFS_S_IFCHR			(1 << 17)
#define	NX_VFS_S_IFBLK			(1 << 18)
#define	NX_VFS_S_IFREG			(1 << 19)
#define	NX_VFS_S_IFLNK			(1 << 20)
#define	NX_VFS_S_IFIFO		    (1 << 21)
#define	NX_VFS_S_IFSOCK			(1 << 22)
#define	NX_VFS_S_IFMT			(NX_VFS_S_IFDIR | NX_VFS_S_IFCHR | NX_VFS_S_IFBLK | NX_VFS_S_IFREG | NX_VFS_S_IFLNK | NX_VFS_S_IFIFO | NX_VFS_S_IFSOCK)

#define NX_VFS_S_ISDIR(m)		((m) & NX_VFS_S_IFDIR )
#define NX_VFS_S_ISCHR(m)		((m) & NX_VFS_S_IFCHR )
#define NX_VFS_S_ISBLK(m)		((m) & NX_VFS_S_IFBLK )
#define NX_VFS_S_ISREG(m)		((m) & NX_VFS_S_IFREG )
#define NX_VFS_S_ISLNK(m)		((m) & NX_VFS_S_IFLNK )
#define NX_VFS_S_ISFIFO(m)		((m) & NX_VFS_S_IFIFO )
#define NX_VFS_S_ISSOCK(m)		((m) & NX_VFS_S_IFSOCK )

#define	NX_VFS_R_OK				(1 << 2)
#define NX_VFS_W_OK				(1 << 1)
#define NX_VFS_X_OK				(1 << 0)

#define NX_VFS_SEEK_SET		    (0)
#define NX_VFS_SEEK_CUR		    (1)
#define NX_VFS_SEEK_END		    (2)

typedef struct NX_VfsStatInfo
{
	NX_U64 ino;
	NX_I64 size;
	NX_U32 mode;
	NX_U64 dev;
	NX_U32 uid;
	NX_U32 gid;
	NX_U64 ctime;
	NX_U64 atime;
	NX_U64 mtime;
} NX_VfsStatInfo;

enum NX_VfsDirentTtpe
{
	NX_VFS_DIR_TYPE_UNK,
	NX_VFS_DIR_TYPE_DIR,
	NX_VFS_DIR_TYPE_CHR,
	NX_VFS_DIR_TYPE_BLK,
	NX_VFS_DIR_TYPE_REG,
	NX_VFS_DIR_TYPE_LNK,
	NX_VFS_DIR_TYPE_FIFO,
	NX_VFS_DIR_TYPE_SOCK,
};

typedef struct NX_VfsDirent
{
	NX_U64 off;
	NX_U32 reclen;
	enum NX_VfsDirentTtpe type;
	char name[NX_VFS_MAX_NAME];
} NX_VfsDirent;

NX_Error NX_VfsMount(const char * dev, const char * dir, const char * fsname, NX_U32 flags);
NX_Error NX_VfsUnmount(const char * path);
NX_Error NX_VfsSync(void);
int NX_VfsOpen(const char * path, NX_U32 flags, NX_U32 mode, NX_Error *outErr);
NX_Error NX_VfsClose(int fd);
NX_U64 NX_VfsRead(int fd, void * buf, NX_U64 len, NX_Error *outErr);
NX_U64 NX_VfsWrite(int fd, void * buf, NX_U64 len, NX_Error *outErr);
NX_Error NX_VfsIoctl(int fd, NX_U32 cmd, void *arg);
NX_I64 NX_VfsFileSeek(int fd, NX_I64 off, int whence, NX_Error *outErr);
NX_Error NX_VfsFileSync(int fd);
NX_Error NX_VfsFileChmod(int fd, NX_U32 mode);
NX_Error NX_VfsFileStat(int fd, NX_VfsStatInfo * st);
int NX_VfsOpenDir(const char * name, NX_Error *outErr);
NX_Error NX_VfsCloseDir(int fd);
NX_Error NX_VfsReadDir(int fd, NX_VfsDirent * dir);
NX_Error NX_VfsRewindDir(int fd);
NX_Error NX_VfsMakeDir(const char * path, NX_U32 mode);
NX_Error NX_VfsRemoveDir(const char * path);
NX_Error NX_VfsRename(const char * src, const char * dst);
NX_Error NX_VfsUnlink(const char * path);
NX_Error NX_VfsAccess(const char * path, NX_U32 mode);
NX_Error NX_VfsChmod(const char * path, NX_U32 mode);
NX_Error NX_VfsStat(const char * path, NX_VfsStatInfo * st);

/* alisa name */
#define NX_FsMount(dev, dir, fsname, flags)     NX_VfsMount(dev, dir, fsname, flags)
#define NX_FsUnmount(path)                      NX_VfsUnmount(path)
#define NX_FsSync()                             NX_VfsSync()
#define NX_FileOpen(path, flags, mode, outErr)  NX_VfsOpen(path, flags, mode, outErr)
#define NX_FileClose(fd)                        NX_VfsClose(fd)
#define NX_FileRead(fd, buf, len, outErr)       NX_VfsRead(fd, buf, len, outErr)
#define NX_FileWrite(fd, buf, len, outErr)      NX_VfsWrite(fd, buf, len, outErr)
#define NX_FileIoctl(fd, cmd, arg)              NX_VfsIoctl(fd, cmd, arg)
#define NX_FileSeek(fd, off, whence, outErr)    NX_VfsFileSeek(fd, off, whence, outErr)
#define NX_FileSync(fd)                         NX_VfsFileSync(fd)
#define NX_FileChmod(fd, mode)                  NX_VfsFileChmod(fd, mode)
#define NX_FileStat(fd, st)                     NX_VfsFileStat(fd, st)
#define NX_DirOpen(name, outErr)                NX_VfsOpenDir(name, outErr)
#define NX_DirClose(fd)                         NX_VfsCloseDir(fd)
#define NX_DirRead(fd, dir)                     NX_VfsReadDir(fd, dir)
#define NX_DirRewind(fd)                        NX_VfsRewindDir(fd)
#define NX_DirCreate(path, mode)                NX_VfsMakeDir(path, mode)
#define NX_DirDelete(path)                      NX_VfsRemoveDir(path)
#define NX_FsRename(src, dst)                   NX_VfsRename(src, dst)
#define NX_FsUnlink(path)                       NX_VfsUnlink(path)
#define NX_FsAccess(path, mode)                 NX_VfsAccess(path, mode)
#define NX_FsChmod(path, mode)                  NX_VfsChmod(path, mode)
#define NX_FsStat(path, st)                     NX_VfsStat(path, st)

#endif  /* __NXBASE___ */
