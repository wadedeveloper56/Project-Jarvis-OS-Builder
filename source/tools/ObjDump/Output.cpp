#include "pch.h"
#include "ObjDump.h"

#define OUT_BUFF_SIZE   1024
#define OUT_BUFF_WRITE  512     /* write outBuff when this full */

static  char            outBuff[OUT_BUFF_SIZE];
static  char* outBuffPtr;
static  FILE* outputFH;
static  size_t          col;
static  const char hexStr[] = "0123456789abcdef";
bool    no_disp = false;

static void flush(void)
{
    size_t  len;

    len = outBuffPtr - outBuff;
    outBuffPtr = outBuff;
    if (len > 0) {
        if (fwrite(outBuff, 1, len, outputFH) != len) {
            fprintf(stderr, "Write error - %s\n", strerror(errno));
            exit(20);    // never return
        }
    }
}

void OutputFini(void)
{
    flush();
}

static char* toHex2(char* p, byte val)
{
    p[1] = hexStr[val & 0xf];
    p[0] = hexStr[val >> 4];
    return(p + 2);
}

static char* toHex4(char* p, unsigned_16 val)
{
    byte    lo;
    byte    hi;

    lo = val & 0xff;
    hi = val >> 8;
    p[1] = hexStr[hi & 0xf];
    p[0] = hexStr[hi >> 4];
    p[3] = hexStr[lo & 0xf];
    p[2] = hexStr[lo >> 4];
    return(p + 4);
}

static char* toHex8(char* p, unsigned_32 val)
{
    unsigned_16 low;
    byte        low_lob;
    byte        low_hib;
    unsigned_16 hiw;
    byte        hiw_lob;
    byte        hiw_hib;

    low = val & 0xffff;
    hiw = val >> 16;
    hiw_lob = hiw & 0xff;
    hiw_hib = hiw >> 8;
    p[1] = hexStr[hiw_hib & 0xf];
    p[0] = hexStr[hiw_hib >> 4];
    p[3] = hexStr[hiw_lob & 0xf];
    p[2] = hexStr[hiw_lob >> 4];
    low_lob = low & 0xff;
    low_hib = low >> 8;
    p[5] = hexStr[low_hib & 0xf];
    p[4] = hexStr[low_hib >> 4];
    p[7] = hexStr[low_lob & 0xf];
    p[6] = hexStr[low_lob >> 4];
    return(p + 8);
}

static char* toDec16(char* dest, unsigned_16 num)
{
    char* orig;
    char* str;
    div_t    res;

    orig = dest;
    str = dest + (3 * sizeof(unsigned) / sizeof(char));
    if (num > 32767) {       /* 'cause div takes ints not unsigneds...*/
        ++dest;
        *--str = '0' + num % 10U;
        num /= 10U;     /* now it should be less than INT_MAX... */
    }
    res.quot = num;
    do {
        ++dest;
        res = div(res.quot, 10);
        *--str = (char)('0' + res.rem);
    } while (res.quot != 0);

    while (dest >= orig) {
        *orig++ = *str++;
    }

    return(dest);
}

static char* to5Dec16(char* dest, unsigned_16 num)
{
    div_t   res;
    char* orig;

    if (num & 0x8000) { // magic index into header file line number table
        *dest++ = '*';
        num &= 0x7FFF;
    }
    else {
        *dest++ = ' ';
    }
    res.quot = num;
    orig = dest;
    dest += 5;
    do {
        res = div(res.quot, 10);
        *--dest = (char)('0' + res.rem);
    } while (res.quot != 0);

    while (dest > orig) {
        *--dest = ' ';
    }
    return(orig + 5);
}

/*
    Output is a customized printf with the following format options:

    %c  same as printf %c
    %s  same as printf %s   (string must be less than OUT_BUFF_WRITE)
    %R  print remainder of RecBuff starting at RecPtr
    %N  print NameLen chars from NamePtr     (implicit arguments)
    %b  same as printf %2.2xh
    %2  same as printf %2.2x
    %x  same as printf %4.4xh
    %X  same as printf %8.8xh
    %8  same as printf %8.8x
    %u  same as printf %u
    %5  same as printf %5u
    %>  arg is number of spaces to print, truncates to 80 spaces
    %<  arg is minimum width of print up to this point (pads with spaces)
    %%  print a %

    Output makes the assumption that % is not followed by the null-
    terminator.
*/
static size_t FmtOutput(const char* fmt, va_list args)
{
    char* p;
    const char* probe;
    const char* str;
    size_t      len;

    p = outBuffPtr;
    while ((probe = strchr(fmt, '%')) != NULL) {
        len = probe - fmt;
        if (len > 0) {
            memcpy(p, fmt, len);
            p += len;
        }
        fmt = probe + 1;
        switch (*fmt) {
            case 'c':
                *p++ = (char)va_arg(args, int);
                break;
            case 's':
                str = va_arg(args, const char*);
                len = strlen(str);
                memcpy(p, str, len);
                p += len;
                break;
            case 'R':
                len = RecLen - RecOffset();
                if (len > OUT_BUFF_WRITE) {
                    len = OUT_BUFF_WRITE;
                }
                memcpy(p, RecPtr, len);
                p += len;
                break;
            case 'N':
                *p++ = '\'';
                memcpy(p, NamePtr, NameLen);
                p += NameLen;
                *p++ = '\'';
                break;
            case 'b':
                p = toHex2(p, (byte)va_arg(args, unsigned));
                *p++ = 'h';
                break;
            case '2':
                p = toHex2(p, (byte)va_arg(args, unsigned));
                break;
            case 'x':
                p = toHex4(p, (unsigned short)va_arg(args, unsigned));
                *p++ = 'h';
                break;
            case 'X':
                p = toHex8(p, va_arg(args, unsigned_32));
                *p++ = 'h';
                break;
            case '8':
                p = toHex8(p, va_arg(args, unsigned_32));
                break;
            case 'u':
                p = toDec16(p, (unsigned short)va_arg(args, unsigned));
                break;
            case '5':
                p = to5Dec16(p, (unsigned short)va_arg(args, unsigned));
                break;
            case '<':
                len = va_arg(args, unsigned);
                while ((size_t)(p - outBuffPtr) < len) {
                    *p++ = ' ';
                }
                break;
            case '>':
                len = va_arg(args, unsigned);
                if (len > 80) {
                    len = 80;
                }
                memset(p, ' ', len);
                p += len;
                break;
            default:
                *p++ = *fmt;
                break;
        }
        ++fmt;
    }
    len = strlen(fmt);
    if (len > 0) {
        memcpy(p, fmt, len);
        p += len;
    }
    outBuffPtr = p;
    *outBuffPtr = '\0';
    return(outBuffPtr - outBuff);
}

size_t Output(const char* fmt, ...)
{
    va_list     args;
    size_t      len;
    char* peol;

    if (no_disp)
        return(0);
    va_start(args, fmt);
    len = FmtOutput(fmt, args);
    va_end(args);
    peol = strrchr(outBuff, '\n');
    if (peol != NULL) {
        col = outBuffPtr - peol;
    }
    else {
        col += len;
    }
    if (len > OUT_BUFF_WRITE)
        flush();
    return(col);
}
