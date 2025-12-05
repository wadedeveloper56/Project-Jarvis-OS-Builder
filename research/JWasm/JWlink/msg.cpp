#include "pch.h"
#include "msg.h"
#include "types.h"
#include "taddr.h"
#include "wlnkmsg.h"
#include "formats.h"
#include "globals.h"
#include "linkutil.h"
#include "banner.h"
#define BAN_VER_STR "1.9" "beta 13"
#define _WLINK_VERSION_         BAN_VER_STR

bool BannerPrinted;
#undef pick
#define pick( num, string ) (char*)string

static char* MsgStrings[] = {
pick(PRODUCT, banner1("JWlink", _WLINK_VERSION_)),
pick(COPYRIGHT, banner2("1985")),
pick(TRADEMARK, banner3),
};
static  char* LocFile;
static  char* LocMem;
static  int             LocRec;
static  MSG_ARG_LIST    MsgArgInfo;
static  char* CurrSymName;

static int UseArgInfo(void)
{
    return(MsgArgInfo.index >= 0);
}

static void IncremIndex(void)
{
    MsgArgInfo.index++;
}

#define IS_VOWEL(c) (((c)=='a')||((c)=='e')||((c)=='i')||((c)=='o')||((c)=='u'))

static unsigned MakeExeName(char* buff, unsigned max)
{
    char        rc_buff[RESOURCE_MAX_SIZE];
    exe_format  format;
    unsigned    len;
    char* str;
    unsigned    num;

    if (max <= 3) return(0);
    len = 1;
    *buff++ = 'a';
    if (FmtData.osname != NULL) {
        str = FmtData.osname;
    }
    else {
        format = FmtData.type;
        /* jwlink: just add PE32+ */
        if ((FmtData.type & MK_PE) && FmtData.u.pe.win64) {
            Msg_Get(MSG_FILE_PE64, rc_buff);
        }
        else if ((FmtData.type & MK_ELF) && FmtData.u.elf.elf64) {
            Msg_Get(MSG_FILE_ELF64, rc_buff);
        }
        else {
            for (;; ) {
                num = blog_32(format);
                format = (exe_format)(format & ~(1 << num));
                if (format == 0)
                    break;
            }
            Msg_Get(MSG_FILE_TYPES_0 + num, rc_buff);
        }
        str = rc_buff;
    }
    if (IS_VOWEL(tolower(*str))) {
        *buff++ = 'n';
        len++;
    }
    *buff++ = ' ';
    num = strlen(str);
    len += num + 2;
    if (len > max) return(len - (num + 2));
    memcpy(buff, str, num);
    buff += num;
    *buff++ = ' ';
    if (FmtData.dll) {
        Msg_Get(MSG_CREATE_TYPE_DLL, rc_buff);
        str = rc_buff;
    }
    else {
        Msg_Get(MSG_CREATE_TYPE_EXE, rc_buff);
        str = rc_buff;
    }
    num = strlen(str);
    len += num;
    if (len > max) return(len - num);
    memcpy(buff, str, num + 1);       /* +1 for the nullchar */
    return(len);
}


unsigned FmtStr(char* buff, unsigned len, char* fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    return(DoFmtStr(buff, len, fmt, &args));
}

unsigned DoFmtStr(char* buff, unsigned len, char* src, va_list* args)
/****************************************************************************/
/* quick vsprintf routine                                           */
/* assumptions - format string does not end in '%'                  */
/*             - only use of '%' is as follows                      */
/*                  %s  : string                                    */
/*                  %tn : n character string (%ns)                  */
/*                  %c  : character                                 */
/*                  %x  : 4 digit hex number (%4x)                  */
/*                  %h  : 8 digit hex number (%8x)                  */
/*                  %d  : decimal                                   */
/*                  %l  : long decimal                              */
/*                  %a  : address   ( %x:%x or 32 bit, depends on format) */
/*                  %A  : address   ( %x:%h or 32 bit, depends on format) */
/*                  %S  : symbol name                               */
/*                  %f  : an executable format name                 */
/********************************************************************/
{
    char            ch;
    char* dest;
    char* str;
    unsigned_16     num;
    unsigned_32     num2;
    unsigned        size;
    targ_addr* addr;
    unsigned int    i;
    static char     hexchar[] = "0123456789abcdef";
    int             temp;

    dest = buff;
    for (;;) {
        ch = *src++;
        if (ch == '\0' || len == 1) break;
        if (ch != '%') {
            *dest++ = ch;
            len--;
        }
        else {
            ch = *src++;
            switch (ch) {
                case 'S':
                    if (UseArgInfo()) {
                        str = MsgArgInfo.arg[MsgArgInfo.index].symb->name;
                        IncremIndex();
                    }
                    else {
                        str = va_arg(*args, symbol*)->name;
                    }
#if defined(__WATCOMC__)
                    if (!(LinkFlags & DONT_UNMANGLE)) {
                        size = __demangle_l(str, 0, dest, len);
                        if (size > (len - 1)) size = len - 1;
                        CurrSymName = dest;
                    }
                    else
#endif
                    {
                        size = strlen(str);
                        if (size > len) size = len;
                        memcpy(dest, str, size);
                        CurrSymName = str;
                    }
                    len -= size;
                    dest += size;
                    break;
                case 's':
                    if (UseArgInfo()) {
                        str = MsgArgInfo.arg[MsgArgInfo.index].string;
                        IncremIndex();
                    }
                    else {
                        str = va_arg(*args, char*);
                    }
                    size = strlen(str);
                    if (size > len) size = len;
                    memcpy(dest, str, size);
                    len -= size;
                    dest += size;
                    break;
                case 't':
                    str = va_arg(*args, char*);
                    num = *src++ - '0';
                    num = num * 10 + *src++ - '0';
                    if (num > len) num = len;
                    while ((*str != '\0') && (num > 0)) {
                        *dest++ = *str++;
                        num--;
                    }
                    while (num > 0) {
                        *dest++ = ' ';
                        num--;
                    }
                    len -= num;
                    break;
                case 'c':
                    *dest++ = va_arg(*args, int);
                    len--;
                    break;
                case 'x':
                    if (UseArgInfo()) {
                        num = MsgArgInfo.arg[MsgArgInfo.index].int_16;
                        IncremIndex();
                    }
                    else {
                        num = va_arg(*args, unsigned int);
                    }
                    if (len < 4) return(dest - buff);    //NOTE: premature return
                    dest += 4;
                    len -= 4;
                    str = dest;
                    for (i = 4; i > 0; i--) {
                        *--str = hexchar[num & 0x0f];
                        num >>= 4;
                    }
                    break;
                case 'h':
                    num2 = va_arg(*args, unsigned_32);
                    if (len < 8) return(dest - buff);     //NOTE: premature return
                    dest += 8;
                    len -= 8;
                    str = dest;
                    for (i = 8; i > 0; i--) {
                        *--str = hexchar[num2 & 0x0f];
                        num2 >>= 4;
                    }
                    break;
                case 'd':
                    if (len < 5) return(dest - buff);    // NOTE: premature return
                    if (UseArgInfo()) {
                        num = MsgArgInfo.arg[MsgArgInfo.index].int_16;
                        IncremIndex();
                    }
                    else {
                        num = va_arg(*args, unsigned int);
                    }
                    _ultoa(num, dest, 10);
                    size = strlen(dest);
                    dest += size;
                    len -= size;
                    break;
                case 'l':
                    if (len < 10) return(dest - buff);   //NOTE: premature return
                    if (UseArgInfo()) {
                        num2 = MsgArgInfo.arg[MsgArgInfo.index].int_32;
                        IncremIndex();
                    }
                    else {
                        num2 = va_arg(*args, unsigned_32);
                    }
                    _ultoa(num2, dest, 10);
                    size = strlen(dest);
                    dest += size;
                    len -= size;
                    break;
                case 'a':
                case 'A':
                    if (UseArgInfo()) {
                        addr = MsgArgInfo.arg[MsgArgInfo.index].address;
                        IncremIndex();
                    }
                    else {
                        addr = va_arg(*args, targ_addr*);
                    }
                    temp = MsgArgInfo.index;
                    MsgArgInfo.index = -1;
                    if (FmtData.type & MK_FLAT) {
                        size = FmtStr(dest, len, (char*)"%h", addr->off);
                    }
                    else if (FmtData.type & MK_QNX_FLAT) {
                        size = FmtStr(dest, len, (char*)"%h", FindLinearAddr(addr));
                    }
                    else if (FmtData.type & (MK_ELF | MK_PE)) {
                        size = FmtStr(dest, len, (char*)"%h", FindLinearAddr2(addr));
                    }
                    else if (FmtData.type & MK_ID_SPLIT) {
                        if (addr->seg == CODE_SEGMENT) {
                            size = FmtStr(dest, len, (char*)"CODE:%h", addr->off);
                        }
                        else {
                            size = FmtStr(dest, len, (char*)"DATA:%h", addr->off);
                        }
                    }
                    else if ((FmtData.type & MK_386) || ch == 'A') {
                        size = FmtStr(dest, len, (char*)"%x:%h", addr->seg, addr->off);
                    }
                    else {
                        size = FmtStr(dest, len, (char*)"%x:%x", addr->seg,
                            (unsigned short)addr->off);
                    }
                    dest += size;
                    len -= size;
                    MsgArgInfo.index = temp;
                    break;
                case 'f':
                    num = MakeExeName(dest, len);
                    dest += num;
                    len -= num;
                    break;
            }
        }
    }
    MsgArgInfo.index = -1;
    *dest = '\0';
    return(dest - buff);
}
