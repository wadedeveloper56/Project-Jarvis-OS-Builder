#pragma once

#include "FileSubsystem.h"
#include "types.h"

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
    //symbol* symb;
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

#define MSG_MAX_ERR_MSG_NUM MSG_UNKNOWN_DIRECTIVE_IGNORED
#define MSG_ARRAY_SIZE ((MSG_MAX_ERR_MSG_NUM / 8) + 1)
#define MAX_MSG_SIZE 512

class MessagingSubsystem
{
    int_8 MsgFlags[MSG_ARRAY_SIZE];
    FileSubsystem* file;
public:
	MessagingSubsystem(FileSubsystem* file);
	~MessagingSubsystem();
};

