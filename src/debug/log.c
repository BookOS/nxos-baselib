#include <nxbase/syscall.h>

NX_Error NX_DebugLog(char *buf, NX_Size len)
{
    return NX_Syscall(NX_API_DebugLog, buf, len);
}
