#pragma once

typedef enum {
    TLT_FORTRAN,
    TLT_ASM,
    TLT_MAX,
    TLT_NONE  = TLT_MAX,
    TLT_C
} TargetLangType;

typedef enum {
    SIZETYPE_16,              // 2 bytes
    SIZETYPE_32,              // 4 bytes
    SIZETYPE_48,              // 6 bytes
    SIZETYPE_MAX
} SizeType;

struct Opt {
    TargetLangType targetLang: 2;
    int signedChar: 1;
    int asmAttachD: 1;
    int prefixStructFields;
    char *structFieldsSep;
    char *conflictPrefix;
    int supressLevel;
    unsigned outLineLen;
    pSLList fileNameList;
    pSLList incPathList;
    SizeType intSize;
    SizeType nearPtrSize;
    SizeType ptrSize;
    SizeType farPtrSize;
    SizeType hugePtrSize;
    int debug;  // Debugging flag, can be turned on by using '-d' option
};

typedef struct {
    int readOnly;  // File/directory is read-only
    char *name;
} FDReadInd, *pFDReadInd;  // File/directory read indicator
