#include "pch.h"
#include "omfreloc.h"
#include "Structs.h"

#define MAX_THREADS 4

bakpat_list* BakPats;
frame_spec       FrameThreads[MAX_THREADS];
frame_spec       TargThreads[MAX_THREADS];

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

void ResetOMFReloc()
{
    BakPats = NULL;
}
