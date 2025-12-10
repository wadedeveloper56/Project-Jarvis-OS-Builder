#include "pch.h"
#include "globals.h"
#include "distrib.h"

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
