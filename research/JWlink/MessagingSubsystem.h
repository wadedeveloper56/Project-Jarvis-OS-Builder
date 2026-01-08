#pragma once

#include "FileSubsystem.h"
#include "globals.h"

#define MSG_LANG_SPACING        1000

enum message_texts {
    MSG_PRODUCT,
    MSG_COPYRIGHT,

#undef pick
#define pick( code, string )  code,
#include   "lnkerror.msg"
#include   "wlink.msg"
#include   "rc.msg"
#undef pick

}; 

enum msg_class {
    OUT_TERM = 0x00100000,
    OUT_MAP = 0x00200000,
    INF = 0x00000000 + OUT_TERM,
    MAP = 0x00000000 + OUT_MAP,
    YELL = 0x00010000 + OUT_TERM,
    WRN = 0x00020000 + OUT_TERM + OUT_MAP,
    MILD_ERR = 0x00030000 + OUT_TERM + OUT_MAP,
    ERR = 0x00040000 + OUT_TERM + OUT_MAP,
    FTL = 0x00050000 + OUT_TERM + OUT_MAP,  /* fatal */
    BANNER = 0x00060000,
    LINE = 0x00080000,
    LOC = 0x00400000,
    LOC_REC = 0x00800000 + LOC,
    CLASS_MSK = 0x00070000,
    OUT_MSK = 0x00300000,
    NUM_MSK = 0x0000ffff,
    NUM_SHIFT = 16
};

enum msg_num {
PRODUCT,
COPYRIGHT,
TRADEMARK,
};

typedef union msg_arg {
    symbol* symb;
    char* string;
    char            c;
    unsigned_16     int_16;
    unsigned_32     int_32;
    targ_addr* address;
} MSG_ARG;

typedef struct msg_arg_list {
    int             index;
    MSG_ARG         arg[5];
} MSG_ARG_LIST;

#define RESOURCE_MAX_SIZE       128
#define MSG_ARRAY_SIZE ((MSG_MAX_ERR_MSG_NUM / 8) + 1)
#define MAX_MSG_SIZE 512

class MessagingSubsystem
{
    char* LocFile;
    char* LocMem;
    int             LocRec;
    MSG_ARG_LIST    MsgArgInfo;
    char* CurrSymName;
    unsigned long   MaxErrors;
    bool            BannerPrinted;
    int_8 MsgFlags[MSG_ARRAY_SIZE];
    FileSubsystem* file;
public:
    MessagingSubsystem(FileSubsystem* file);
    ~MessagingSubsystem();
    unsigned FmtStr(char*, unsigned, char*, ...);
    unsigned DoFmtStr(char*, unsigned, char*, va_list*);
    void     LnkMsg(unsigned, char*, ...);
    void LnkFatal(char* msg);
    void     Locator(char*, char*, unsigned);
    void     WLPrtBanner(void);
    //bool     SkipSymbol(symbol*);
    int      SymAlphaCompare(const void*, const void*);
    unsigned CalcMsgNum(unsigned);

    void     ResetMsg(void);
    int      Msg_Get(int resourceid, char buffer[]);
    void     Msg_Do_Put_Args(char rc_buff[], MSG_ARG_LIST*, char*, ...);
    void     Msg_Put_Args(char rc_buff[], MSG_ARG_LIST*, char*, va_list*);

private:
    void Msg_Add_Arg(MSG_ARG* arginfo, char typech, va_list* args);
    void LocateFile(unsigned num);
    void FileOrder(char rc_buff[], int which_file);
    void MessageFini(unsigned num, char* buff, unsigned len, char* prefix, unsigned prefixlen, bool waserror);
};


