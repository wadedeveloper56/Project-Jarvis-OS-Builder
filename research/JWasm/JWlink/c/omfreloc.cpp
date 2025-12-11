#include "pch.h"
#include "globals.h"
#include "omfreloc.h"
#include "obj2supp.h"

typedef struct bakpatlist {
    struct bakpatlist* next;
    virt_mem            addr;
    unsigned_16         len;
    byte                loctype;
    bool                is32bit;
    char                data[1];
} bakpat_list;

static bakpat_list* BakPats;

#define MAX_THREADS 4

static frame_spec       FrameThreads[MAX_THREADS];
static frame_spec       TargThreads[MAX_THREADS];

static fix_type RelocTypeMap[] = {
    FIX_OFFSET_8,       // LOC_OFFSET_LO
    FIX_OFFSET_16,      // LOC_OFFSET
    FIX_BASE,           // LOC_BASE
    FIX_BASE_OFFSET_16, // LOC_BASE_OFFSET
    FIX_HIGH_OFFSET_8,  // LOC_OFFSET_HI
    FIX_OFFSET_32,      // LOC_OFFSET_32
    FIX_BASE_OFFSET_32, // LOC_BASE_OFFSET_32
    (fix_type)(FIX_OFFSET_16 | FIX_LOADER_RES)      // modified loader resolved off_16
};

static void GetTarget(unsigned loc, frame_spec* targ, struct objbuff*);
static void GetFrame(unsigned frame, frame_spec* refframe, struct objbuff*);

void ResetOMFReloc(void)
{
    BakPats = NULL;
}
