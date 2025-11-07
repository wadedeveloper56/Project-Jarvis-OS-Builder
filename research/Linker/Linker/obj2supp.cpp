#include "pch.h"
#include "linkstd.h"
#include "reloc.h"
#include "pcobj.h"
#include "newmem.h"
#include "msg.h"
#include "alloc.h"
#include "mapio.h"
#include "exeos2.h"
#include "exeqnx.h"
#include "exeelf.h"
#include "loadfile.h"
#include "loados2.h"
#include "loadnov.h"
#include "loadqnx.h"
#include "loadelf.h"
#include "wlnkmsg.h"
#include "virtmem.h"
#include "objpass2.h"
#include "objstrip.h"
#include "objcalc.h"
#include "impexp.h"
#include "overlays.h"
#include "strtab.h"
#include "carve.h"
#include "permdata.h"
#include "dbgcomm.h"
#include "dbgall.h"
#include "dbgcv.h"
#include "toc.h"
#include "ring.h"
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
