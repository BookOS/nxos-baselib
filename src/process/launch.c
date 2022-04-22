#include <nxbase/syscall.h>

NX_Error NX_ProcessLaunch(char *path, NX_U32 flags, int *retCode, char *cmd, char *env)
{
    return NX_Syscall5(NX_API_ProcessLaunch, path, flags, retCode, cmd, env);
}
