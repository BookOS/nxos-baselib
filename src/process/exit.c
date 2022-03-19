#include <nxbase/syscall.h>

void NX_ProcessExit(NX_Error errCode)
{
    NX_Syscall(NX_API_ProcessExit, errCode);
}
