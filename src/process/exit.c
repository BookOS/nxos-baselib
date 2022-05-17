#include <nxbase/syscall.h>

void NX_ProcessExit(NX_U32 exitCode)
{
    NX_Syscall(NX_API_ProcessExit, exitCode);
}
