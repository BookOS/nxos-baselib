#include <nxbase/utils.h>

#define __CMD_DELIMITER ' '
#define __ENV_DELIMITER ':'

NX_PRIVATE int __ParseLine(char * buf, char * argArray[], int maxArgs, char delimiter)
{
    char * line;
    int argc;

    if (buf == NX_NULL || argArray == NX_NULL || !maxArgs)
    {
        return -1;
    }
    
    argc = 0;
    line = buf;
    
    while (argc < maxArgs && *line != '\0')
    {
        /* skip delimiter */
        while (*line == delimiter)
        {
            line++;
        }

        if (delimiter == __ENV_DELIMITER)
        {
            if (*line != '/') /* env must begin with root dir */
            {
                return -1;
            }
        }

        char * p = NX_StrChr(line, delimiter);
        if (p == NX_NULL) /* no spilit char */
        {
            argArray[argc++] = line;
            argArray[argc] = NX_NULL;
            return argc;
        }
        else
        {
            /* clear delimiter */
            while (*p == delimiter)
            {
                *p = '\0';
                p++;
            }
            
            argArray[argc++] = line;
            line = p;
        }
    }
    
    argArray[argc + 1] = NX_NULL;
    return argc;
}

NX_PRIVATE int __BuildLine(char * buf, int bufLen, char * argArray[], char delimiter)
{
    int argc;

    if (buf == NX_NULL || argArray == NX_NULL || !bufLen)
    {
        return -1;
    }
    
    NX_MemZero(buf, bufLen);

    argc = 0;
    while (argArray[argc] != NX_NULL)
    {
        /* buf len + str len + delimiter len */
        if (NX_StrLen(buf) + NX_StrLen(argArray[argc]) + 1 >= bufLen)
        {
            return -1;
        }

        NX_StrCat(buf, argArray[argc]);
        
        if (argArray[argc + 1] != NX_NULL)
        {
            char s[2] = {delimiter, 0};
            NX_StrCat(buf, s);
        }
        argc++;
    }
    return argc;
}

int NX_EnvToArray(char * buf, char * argArray[], int maxArgs)
{
    return __ParseLine(buf, argArray, maxArgs, __ENV_DELIMITER);
}

int NX_CmdToArray(char * buf, char * argArray[], int maxArgs)
{
    return __ParseLine(buf, argArray, maxArgs, __CMD_DELIMITER);
}

int NX_EnvToBuf(char * buf, int bufLen, char * argArray[])
{
    return __BuildLine(buf, bufLen, argArray, __ENV_DELIMITER);
}

int NX_CmdToBuf(char * buf, int bufLen, char * argArray[])
{
    return __BuildLine(buf, bufLen, argArray, __CMD_DELIMITER);
}
