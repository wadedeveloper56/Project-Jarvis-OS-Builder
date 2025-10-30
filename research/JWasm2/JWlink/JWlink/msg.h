#pragma once

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

void LnkMsg(unsigned    num, char* types, ...);
