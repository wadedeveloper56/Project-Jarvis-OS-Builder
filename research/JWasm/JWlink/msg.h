#pragma once

#if !defined(pick)
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


#define pick( name, string ) name

enum msg_num {
#else
#include <banner.h>
#endif

#if 0
#define IDV     "** EXPERIMENTAL ** "
#elif _DEVELOPMENT == _ON
#define IDV   " **INTERNAL DEVELOPMENT** "
#else
#define IDV
#endif

pick(PRODUCT, banner1(IDV "JWlink", _WLINK_VERSION_)),
pick(COPYRIGHT, banner2("1985")),
pick(TRADEMARK, banner3),
//pick( TRADEMARK2,               banner3a ),
};
#include "standard.h"
#include "types.h"
#define MAX_MSG_SIZE 512

extern unsigned long    MaxErrors;
extern byte             MsgFlags[];
extern bool             BannerPrinted;

unsigned FmtStr(char* buff, unsigned len, char* fmt, ...);
unsigned DoFmtStr(char* buff, unsigned len, char* src, va_list* args);
unsigned_16 blog_32(unsigned_32 value);
