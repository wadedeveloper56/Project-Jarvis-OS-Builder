#pragma once

#include <cstdarg>
#include <ctype.h>
#include "globals.h"
#include "types.h"
#include "lnkmsg.h"
#include "LinkerUtils.h"
#include "FileSubsystem.h"

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
    void     Locator(char*, char*, unsigned);
    void     WLPrtBanner(void);
    bool     SkipSymbol(symbol*);
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

