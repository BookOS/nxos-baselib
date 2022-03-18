#include <nxbase/core/syscall.h>

void NX_ProcessExit(int exitCode)
{
    NX_Syscall(NX_API_ProcessExit, exitCode);
}
