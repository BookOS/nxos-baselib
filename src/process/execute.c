#include <nxbase/core/syscall.h>

NX_Error NX_ProcessExecute(char *name, char *path, NX_U32 flags)
{
    NX_Syscall(NX_API_ProcessExit, exitCode);
}
