#include <nxbase/syscall.h>

NX_Error NX_ProcessCreate(char *name, char *path, NX_U32 flags)
{
    return NX_Syscall(NX_API_ProcessCreate, name, path, flags);
}