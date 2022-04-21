#include <nxbase/syscall.h>

NX_Error NX_ProcessWait(int pid, int *retCode)
{
    return NX_Syscall2(NX_API_ProcessWait, pid, retCode);
}
