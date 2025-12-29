#include "pch.h"
#include "globals.h"
#include "obj2supp.h"

typedef struct fix_data {
    byte* data;
    unsigned_32 value;              /* value at location being patched */
    unsigned_32 hvalue;             /* jwlink: in case value is 64-bit */
    targ_addr   loc_addr;
    targ_addr   tgt_addr;
    fix_type    type;
    unsigned    ffix : 3;
    unsigned    additive : 1;
    unsigned    done : 1;
    unsigned    imported : 1;
    unsigned    os2_selfrel : 1;
} fix_data;

static offset           LastOptimized;  // offset last optimized.
static fix_type         LastOptType;
static segdata* LastSegData;
static offset           FixupOverflow;

#define MAX_ADDEND_SIZE ( 2 * sizeof( unsigned_32 ) )
#define GET_S16( P )    (*(signed_16 *)(P))
#define FIX_POINTER_MASK ( FIX_BASE | FIX_HIGH | FIX_OFFSET_MASK )

void ResetObj2Supp(void)
{
    FixupOverflow = 0;
    LastOptType = (fix_type)0;
    LastOptimized = 0xFFFFFFFF;
}

