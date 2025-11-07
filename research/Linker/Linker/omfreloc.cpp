#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "alloc.h"
#include "newmem.h"
#include "virtmem.h"
#include "reloc.h"
#include <pcobj.h>
#include <string.h>
#include "obj2supp.h"
#include "objnode.h"
#include "objio.h"
#include "overlays.h"
#include "objstrip.h"
#include "objomf.h"
#include "objpass2.h"
#include "ring.h"
#include "omfreloc.h"

#if BORLAND_EXT==0
#define FindSegNode FindNode
#else
void* FindSegNode(NODEARRAY* list, unsigned index);
#endif

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

void ResetOMFReloc(void)
{
    BakPats = NULL;
}
