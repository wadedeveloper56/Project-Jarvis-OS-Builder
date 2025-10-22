#include "pch.h"
#include "globals.h"
#include "memalloc.h"
#include "parser.h"
#include "preproc.h"
#include "expreval.h"
#include "equate.h"
#include "input.h"
#include "tokenize.h"
#include "macro.h"
#include "condasm.h"
#include "listing.h"
#include "myassert.h"


static const char __digits[17] = { "0123456789ABCDEF" };

char* myltoa(uint_32 value, char* buffer, unsigned radix, bool sign, bool addzero)
{
    char* p;
    char* dst = buffer;
    char   tmpbuf[34];

#ifdef DEBUG_OUT
    uint_32 saved_value = value;
#endif
    if (sign) {
        *dst++ = '-';
        value = 0 - value;
    }
    else if (value == 0) {
        *dst++ = '0';
        *dst = NULLC;
        return(buffer);
    }
    for (p = &tmpbuf[33], *p = NULLC; value; value = value / radix)
        *(--p) = __digits[value % radix];
    if (addzero && (*p > '9'))            
        *dst++ = '0';
    memcpy(dst, p, &tmpbuf[33] + 1 - p);
    DebugMsg1(("myltoa( value=%" I32_SPEC "Xh, out=%s, radix=%u, sign=%u, %u)\n", saved_value, buffer, radix, sign, addzero));
    return(buffer);
}

