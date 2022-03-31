/**
 * Copyright (c) 2018-2022, NXOS Development Team
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Contains: sprintf
 * 
 * Change Logs:
 * Date           Author            Notes
 * 2022-4-1       JasonHu           Init
 */

#include <nxbase/utils.h>

#define ZEROPAD	1		/* pad with zero */
#define SIGN	2		/* unsigned/signed long */
#define PLUS	4		/* show plus */
#define SPACE	8		/* space if plus */
#define LEFT	16		/* left justified */
#define SPECIAL	32		/* 0x */
#define SMALL	64		/* use 'abcdef' instead of 'ABCDEF' */

#define IsDigit(c)	((c) >= '0' && (c) <= '9')

NX_PRIVATE int SkipAscii2Int(const char **s)
{
	int i = 0;
	while (IsDigit(**s))
    {
		i = i * 10 + *((*s)++) - '0';
    }
	return i;
}

NX_PRIVATE int _Div(unsigned long *num, char base) 
{
    int ret = *num % base;
    *num = *num / base;
    return ret;
}

NX_PRIVATE char *_Number(char * str, long num, int base, int size, int precision,	int type)
{
	char c, sign, tmp[50];
	const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;

	if (type & SMALL)
    {
        digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    }
    if (type & LEFT)
    {
        type &= ~ZEROPAD;
    }
	if (base < 2 || base > 36)
    {
		return 0;
    }

	c = (type & ZEROPAD) ? '0' : ' ' ;
	sign = 0;
	if ((type & SIGN) && num < 0)
    {
		sign='-';
		num = -num;
	}
    else
    {
		sign = (type & PLUS) ? '+' : ((type & SPACE) ? ' ' : 0);
    }

	if (sign)
    {
        size--;
    }

	if (type & SPECIAL)
    {
        if (base == 16)
        {
            size -= 2;
        }
		else if (base == 8)
        {
            size--;
        }
    }
    i = 0;
	if (num == 0)
    {
		tmp[i++]='0';
    }
	else
    {
        while (num!=0)
        {
		    tmp[i++] = digits[_Div((unsigned long *)&num, base)];
        }
    }
    if (i > precision)
    {
        precision = i;
    }
	size -= precision;
	if (!(type & (ZEROPAD + LEFT)))
    {
        while(size-- > 0)
        {
			*str++ = ' ';
        }
    }
    if (sign)
    {
		*str++ = sign;
    }
	if (type & SPECIAL)
    {
        if (base == 8)
        {
			*str++ = '0';
        }
		else if (base == 16) 
		{
			*str++ = '0';
			*str++ = digits[33];
		}
    }
    if (!(type & LEFT))
    {
        while(size-- > 0)
        {
			*str++ = c;
        }
    }
		
	while(i < precision--)
    {
		*str++ = '0';
    }
	while(i-- > 0)
    {
		*str++ = tmp[i];
    }
	while(size-- > 0)
    {
		*str++ = ' ';
    }
	return str;
}

int NX_StrPrintfVarN(char *buf, int bufLen, const char *fmt, NX_VarList args)
{
	char *str, *s;
	int flags;
	int fieldWidth;
	int precision;
	int len, i;
	int qualifier;		/* 'h', 'l', 'L' or 'Z' for integer fields */

	for(str = buf; *fmt && bufLen--; fmt++)
	{
		if(*fmt != '%')
		{
			*str++ = *fmt;
			continue;
		}
		flags = 0;
    repeat:
        fmt++;
        switch(*fmt)
        {
        case '-':flags |= LEFT;	
            goto repeat;
        case '+':flags |= PLUS;	
            goto repeat;
        case ' ':flags |= SPACE;	
            goto repeat;
        case '#':flags |= SPECIAL;	
            goto repeat;
        case '0':flags |= ZEROPAD;	
            goto repeat;
        }

        /* get field width */
        fieldWidth = -1;
        if(IsDigit(*fmt))
        {
            fieldWidth = SkipAscii2Int(&fmt);
        }
        else if(*fmt == '*')
        {
            fmt++;
            fieldWidth = NX_VarArg(args, int);
            if(fieldWidth < 0)
            {
                fieldWidth = -fieldWidth;
                flags |= LEFT;
            }
        }
        
        /* get the precision */
        precision = -1;
        if(*fmt == '.')
        {
            fmt++;
            if(IsDigit(*fmt))
            {
                precision = SkipAscii2Int(&fmt);
            }
            else if(*fmt == '*')
            {	
                fmt++;
                precision = NX_VarArg(args, int);
            }
            if(precision < 0)
            {
                precision = 0;
            }
        }
        
        qualifier = -1;
        if(*fmt == 'h' || *fmt == 'l' || *fmt == 'L' || *fmt == 'Z')
        {	
            qualifier = *fmt;
            fmt++;
        }

        switch(*fmt)
        {
        case 'c':
            if(!(flags & LEFT))
            {
                while(--fieldWidth > 0)
                {
                    *str++ = ' ';
                }
            }
            *str++ = (unsigned char)NX_VarArg(args, int);
            while(--fieldWidth > 0)
            {
                *str++ = ' ';
            }
            break;
        case 's':
            s = NX_VarArg(args,char *);
            if(!s)
            {
                s = '\0';
            }
            len = NX_StrLen(s);
            if(precision < 0)
            {
                precision = len;
            }
            else if(len > precision)
            {
                len = precision;
            }
            
            if(!(flags & LEFT))
            {
                while(len < fieldWidth--)
                {
                    *str++ = ' ';
                }
            }
            for(i = 0;i < len ;i++)
            {
                *str++ = *s++;
            }
            while(len < fieldWidth--)
            {
                *str++ = ' ';
            }
            break;

        case 'o':
            if(qualifier == 'l')
            {
                str = _Number(str, NX_VarArg(args, unsigned long), 8, fieldWidth, precision, flags);
            }
            else
            {
                str = _Number(str, NX_VarArg(args, unsigned int), 8, fieldWidth, precision, flags);
            }
            break;

        case 'p':
            if(fieldWidth == -1)
            {
                fieldWidth = 2 * sizeof(void *);
                flags |= ZEROPAD;
            }

            str = _Number(str, (unsigned long)NX_VarArg(args, void *), 16, fieldWidth, precision, flags);
            break;

        case 'x':
            flags |= SMALL;

        case 'X':
            if(qualifier == 'l')
            {
                str = _Number(str, NX_VarArg(args, unsigned long), 16, fieldWidth, precision, flags);
            }
            else
            {
                str = _Number(str, NX_VarArg(args, unsigned int), 16, fieldWidth, precision, flags);
            }
            break;

        case 'd':
        case 'i':
            flags |= SIGN;
        case 'u':
            if(qualifier == 'l')
            {
                str = _Number(str, NX_VarArg(args, long), 10, fieldWidth, precision, flags);
            }
            else
            {
                str = _Number(str, NX_VarArg(args, int), 10, fieldWidth, precision, flags);
            }
            break;

        case 'n':
            if(qualifier == 'l')
            {
                long *ip = NX_VarArg(args, long *);
                *ip = (str - buf);
            }
            else
            {
                int *ip = NX_VarArg(args, int *);
                *ip = (str - buf);
            }
            break;

        case '%':
            *str++ = '%';
            break;

        default:
            *str++ = '%';	
            if(*fmt)
            {
                *str++ = *fmt;
            }
            else
            {
                fmt--;
            }
            break;
        }
	}
	*str = '\0';
	return str - buf;
}

int NX_StrPrintfN(char *buf, int buflen, const char *fmt, ...)
{
	NX_VarList arg;
	NX_VarStart(arg, fmt);
	return NX_StrPrintfVarN(buf, buflen, fmt, arg);
}
