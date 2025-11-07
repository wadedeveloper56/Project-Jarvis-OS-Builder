#include "pch.h"
#include "linkstd.h"
#include "alloc.h"
#include "msg.h"
#include "pcobj.h"
#include "wlnkmsg.h"
#include "objpass1.h"
#include "objpass2.h"
#include "objfree.h"
#include "wcomdef.h"
#include "overlays.h"
#include "ring.h"
#include "distrib.h"
#include "specials.h"
#include "load16m.h"

static unsigned_16  CurrModThere;
static arcdata* ArcBuffer;
static unsigned_32  ArcBufLen;
static mod_entry** ModTable;
static unsigned_16  CurrModHandle;

section** SectOvlTab;

#define MOD_DEREF( x )  (ModTable[(x)])
#define INITIAL_MOD_ALLOC 32
#define INITIAL_ARC_ALLOC 32
#define MAX_NUM_MODULES   (8 * 1024)

void ResetDistrib(void)
{
    ArcBuffer = NULL;
    ModTable = NULL;
    SectOvlTab = NULL;
}
