#pragma once

#include <limits.h>

#define MAX_TOKEN_SIZE          501 /* max tok size is 500 + terminating 0 */
#define MAX_PRINT_TOKEN_SIZE    (MAX_TOKEN_SIZE+10)
#define MAX_INCLUDE_NEST        20  /* #include nesting level */
#define TAB_SIZE                8


typedef enum {
    CONSTT_CHAR_CONST,
    CONSTT_INT_CONST,
    CONSTT_UINT_CONST,
    CONSTT_LONG_CONST,
    CONSTT_ULONG_CONST,
    CONSTT_FLOAT_CONST,
    CONSTT_DOUBLE_CONST,
    CONSTT_LDOUBLE_CONST,   /* Long double const */
    CONSTT_STRING_CONST,
    CONSTT_MAX
} ConstType;

typedef enum {
    TT_PREPROCESSOR,
    TT_OTHER
} token_type;

/* Tokenizer states */
typedef enum {
    TS_START,
    TS_COMMENT
} TStates;

#define MAX_LINE_NUM    SHRT_MAX
#define MAX_COL_NUM     SHRT_MAX
typedef struct {
    char *fileName;
    int8 fileLevel;
    int16 lineNum;
    int16  colNum;
    uint8  linesBefore;
    uint8  spacesBefore;

    long orderLineNum;

} TokPos, *pTokPos;

typedef enum {
    RADT_DECIMAL,
    RADT_HEX,
    RADT_OCTAL,
    RADT_MAX
} RadixType;


typedef struct {
    uint16 code;
    union {
        struct {      // General info
            char* string;
            pDeclInfo pTypeDecl;  // This only points to a symbol table entry
        } ginfo;
        struct {
            ConstType type: 6;
            RadixType radix: 2;
            union {
                unsigned long lIntConst;
                long double lDoubleConst;
                long double data;
            } repr;
        } constant;
        struct {
            char *s;
            int strLen;
        } s;  // String representation
    } repr;
} *pTokData;

typedef struct {
    pTokData data;
    pTokPos pos;
} *pToken;

