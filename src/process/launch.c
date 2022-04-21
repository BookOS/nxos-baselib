#include <nxbase/syscall.h>

NX_Error NX_ProcessLaunch(char *name, char *path, NX_U32 flags, int *outPid)
{
    return NX_Syscall4(NX_API_ProcessCreate, name, path, flags, outPid);
}
