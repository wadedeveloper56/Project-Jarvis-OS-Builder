#include "pch.h"
#include "linkstd.h"
#include "pcobj.h"
#include "newmem.h"
#include "msg.h"
#include "alloc.h"
#include "reloc.h"
#include "wlnkmsg.h"
#include "virtmem.h"
#include "fileio.h"
#include "mapio.h"
#include "procfile.h"
#include "objcalc.h"
#include "objfree.h"
#include "dbgall.h"
#include "objpass1.h"
#include "loadfile.h"
#include "loaddos.h"
#include "objnode.h"
#include "distrib.h"
#include "overlays.h"
#include "ring.h"
#include "specials.h"

static segdata* OvlSegData;
static symbol* OverlayTable;   /* symbol entry for overlay table */
static symbol* OverlayTableEnd;/* symbol entry for overlay table */
static symbol* OvlVecStart;    /* symbol entry for overlay vector start */
static symbol* OvlVecEnd;      /* symbol entry for overlay vector end */
static targ_addr    OvlvecAddr;      /* address of overlay vectors */
static targ_addr    Stash;

unsigned_16         AreaSize;

void ResetOvlSupp(void)
{
    AreaSize = 0xFFFF;
}
