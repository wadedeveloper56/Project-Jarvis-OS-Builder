#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

typedef enum _boolean {FALSE=false, TRUE=true} boolean;

/* "Native" "word" size for intnum calculations. */
#define BITVECT_NATIVE_SIZE     256

#define BIT_VECTOR_HIDDEN_WORDS 3

#define and         &&      /* logical (boolean) operators: lower case */
#define or          ||
#define not         !

#define AND         &       /* binary (bitwise) operators: UPPER CASE */
#define OR          |
#define XOR         ^
#define NOT         ~
#define SHL         <<
#define SHR         >>

/* constants describing parameters of internal floating point format */
#define MANT_BITS       80
#define MANT_BYTES      10
#define MANT_SIGDIGITS  24
#define EXP_BIAS        0x7FFF
#define EXP_INF         0xFFFF
#define EXP_MAX         0xFFFE
#define EXP_MIN         1
#define EXP_ZERO        0

#define bits_(BitVector) *(BitVector-3)
#define size_(BitVector) *(BitVector-2)
#define mask_(BitVector) *(BitVector-1)

/** Warning classes (that may be enabled/disabled). */
typedef enum yasm_warn_class {
    YASM_WARN_NONE = 0,     /**< No warning */
    YASM_WARN_GENERAL,      /**< Non-specific warnings */
    YASM_WARN_UNREC_CHAR,   /**< Unrecognized characters (while tokenizing) */
    YASM_WARN_PREPROC,      /**< Preprocessor warnings */
    YASM_WARN_ORPHAN_LABEL, /**< Label alone on a line without a colon */
    YASM_WARN_UNINIT_CONTENTS, /**< Uninitialized space in code/data section */
    YASM_WARN_SIZE_OVERRIDE,/**< Double size override */
    YASM_WARN_IMPLICIT_SIZE_OVERRIDE /**< Implicit size override */
} yasm_warn_class;

/** Error classes.  Bitmask-based to support limited subclassing. */
typedef enum yasm_error_class {
    YASM_ERROR_NONE = 0x0000, /**< No error */
    YASM_ERROR_GENERAL = 0xFFFF, /**< Non-specific */
    YASM_ERROR_ARITHMETIC = 0x0001, /**< Arithmetic error (general) */
    YASM_ERROR_OVERFLOW = 0x8001, /**< Arithmetic overflow */
    YASM_ERROR_FLOATING_POINT = 0x4001, /**< Floating point error */
    YASM_ERROR_ZERO_DIVISION = 0x2001, /**< Divide-by-zero */
    YASM_ERROR_ASSERTION = 0x0002, /**< Assertion error */
    YASM_ERROR_VALUE = 0x0004, /**< Value inappropriate
                                           *   (e.g. not in range) */
    YASM_ERROR_NOT_ABSOLUTE = 0x8004, /**< Absolute expression required */
    YASM_ERROR_TOO_COMPLEX = 0x4004, /**< Expression too complex */
    YASM_ERROR_NOT_CONSTANT = 0x2004, /**< Constant expression required */
    YASM_ERROR_IO = 0x0008, /**< I/O error */
    YASM_ERROR_NOT_IMPLEMENTED = 0x0010, /**< Not implemented error */
    YASM_ERROR_TYPE = 0x0020, /**< Type error */
    YASM_ERROR_SYNTAX = 0x0040, /**< Syntax error */
    YASM_ERROR_PARSE = 0x8040  /**< Parser error */
} yasm_error_class;

typedef enum ErrCode
{
    ErrCode_Ok = 0,    /* everything went allright                       */

    ErrCode_Type,      /* types word and size_t have incompatible sizes  */
    ErrCode_Bits,      /* bits of word and sizeof(word) are inconsistent */
    ErrCode_Word,      /* size of word is less than 16 bits              */
    ErrCode_Long,      /* size of word is greater than size of long      */
    ErrCode_Powr,      /* number of bits of word is not a power of two   */
    ErrCode_Loga,      /* error in calculation of logarithm              */

    ErrCode_Null,      /* unable to allocate memory                      */

    ErrCode_Indx,      /* index out of range                             */
    ErrCode_Ordr,      /* minimum > maximum index                        */
    ErrCode_Size,      /* bit vector size mismatch                       */
    ErrCode_Pars,      /* input string syntax error                      */
    ErrCode_Ovfl,      /* numeric overflow error                         */
    ErrCode_Same,      /* operands must be distinct                      */
    ErrCode_Expo,      /* exponent must be positive                      */
    ErrCode_Zero       /* division by zero error                         */
} ErrCode;

#define BIT_VECTOR_ZERO_WORDS(target,count) \
    while (count-- > 0) *target++ = 0;

#define BIT_VECTOR_FILL_WORDS(target,fill,count) \
    while (count-- > 0) *target++ = fill;

#define BIT_VECTOR_FLIP_WORDS(target,flip,count) \
    while (count-- > 0) *target++ ^= flip;

#define STAILQ_ENTRY(type)                                              \
struct {                                                                \
        struct type *stqe_next; /* next element */                      \
}

#define STAILQ_FIRST(head)      ((head)->stqh_first)

#define STAILQ_INIT(head) do {                                          \
        STAILQ_FIRST((head)) = NULL;                                    \
        (head)->stqh_last = &STAILQ_FIRST((head));                      \
} while (0)

#define STAILQ_HEAD(name, type)                                         \
struct name {                                                           \
        struct type *stqh_first;/* first element */                     \
        struct type **stqh_last;/* addr of last next element */         \
}

/* Warning indicator */
typedef struct warn {
    STAILQ_ENTRY(warn) link;
    yasm_warn_class wclass;
    char* wstr;
} warn;

typedef  unsigned   char    N_char;
typedef  unsigned   char    N_byte;
typedef  unsigned   short   N_short;
typedef  unsigned   short   N_shortword;
typedef  unsigned   int     N_int;
typedef  unsigned   int     N_word;
typedef  unsigned   long    N_long;
typedef  unsigned   long    N_longword;

/*  Mnemonic 1:  The natural numbers,  N = { 0, 1, 2, 3, ... }               */
/*  Mnemonic 2:  Nnnn = u_N_signed,  _N_ot signed                            */
typedef  signed     char    Z_char;
typedef  signed     char    Z_byte;
typedef  signed     short   Z_short;
typedef  signed     short   Z_shortword;
typedef  signed     int     Z_int;
typedef  signed     int     Z_word;
typedef  signed     long    Z_long;
typedef  signed     long    Z_longword;

/*  Mnemonic 1:  The whole numbers,  Z = { 0, -1, 1, -2, 2, -3, 3, ... }     */
/*  Mnemonic 2:  Zzzz = Ssss_igned                                           */
typedef  void* voidptr;
typedef  N_char* charptr;
typedef  N_byte* byteptr;
typedef  N_short* shortptr;
typedef  N_shortword* shortwordptr;
typedef  N_int* intptr;
typedef  N_word* wordptr;
typedef  N_long* longptr;
typedef  N_longword* longwordptr;
typedef  N_char* N_charptr;
typedef  N_byte* N_byteptr;
typedef  N_short* N_shortptr;
typedef  N_shortword* N_shortwordptr;
typedef  N_int* N_intptr;
typedef  N_word* N_wordptr;
typedef  N_long* N_longptr;
typedef  N_longword* N_longwordptr;
typedef  Z_char* Z_charptr;
typedef  Z_byte* Z_byteptr;
typedef  Z_short* Z_shortptr;
typedef  Z_shortword* Z_shortwordptr;
typedef  Z_int* Z_intptr;
typedef  Z_word* Z_wordptr;
typedef  Z_long* Z_longptr;
typedef  Z_longword* Z_longwordptr;

typedef struct BitVector_from_Dec_static_data {
    wordptr term;
    wordptr base;
    wordptr prod;
    wordptr rank;
    wordptr temp;
}BitVector_from_Dec_static_data;

typedef struct _yasm_floatnum {
    wordptr mantissa;        /* Allocated to MANT_BITS bits */
    unsigned short exponent;
    unsigned char sign;
    unsigned char flags;
}yasm_floatnum;

typedef struct POT_Entry_s {
    yasm_floatnum f;
    int dec_exponent;
} POT_Entry;

/* "Source" for POT_Entry. */
typedef struct POT_Entry_Source_s {
    unsigned char mantissa[MANT_BYTES];     /* little endian mantissa */
    unsigned short exponent;                /* Bias 32767 exponent */
} POT_Entry_Source;

extern char* yasm_estr;
extern unsigned long yasm_exrefline;
extern char* yasm_exrefstr; 
extern yasm_error_class yasm_eclass;
extern unsigned long warn_class_enabled;
extern wordptr conv_bv;
extern wordptr result, spare, op1static, op2static;
extern BitVector_from_Dec_static_data* from_dec_data;

extern void (*yasm_internal_error_)(const char* file, unsigned int line, const char* message);
extern void (*yasm_fatal) (const char* message, va_list va);
extern const char* (*yasm_gettext_hook) (const char* msgid);

ErrCode BitVector_Boot(void);                 /* 0 = ok, 1..7 = error */
void yasm_errwarn_initialize(void);
void yasm__fatal(const char* message, ...);
extern void* (*yasm_xmalloc) (size_t size);

extern N_word BITS;     /* = # of bits in machine word (must be power of 2)  */
extern N_word MODMASK;  /* = BITS - 1 (mask for calculating modulo BITS)     */
extern N_word LOGBITS;

N_word BitVector_Size(N_int bits);
N_word BitVector_Mask(N_int bits);
void BitVector_Block_Store(wordptr addr, charptr buffer, N_int length);
wordptr BitVector_Create(N_int bits, boolean clear);
BitVector_from_Dec_static_data* BitVector_from_Dec_static_Boot(N_word bits);

void yasm_intnum_initialize(void);
void yasm_floatnum_initialize(void);
