#include "pch.h"
#include "globals.h"
#include "objstruct.h"
#include "objpass1.h"
#include "distrib.h"

static segdata* OvlSegData;
static symbol* OverlayTable;   /* symbol entry for overlay table */
static symbol* OverlayTableEnd;/* symbol entry for overlay table */
static symbol* OvlVecStart;    /* symbol entry for overlay vector start */
static symbol* OvlVecEnd;      /* symbol entry for overlay vector end */
static targ_addr    OvlvecAddr;      /* address of overlay vectors */
static targ_addr    Stash;

unsigned_16         AreaSize;

void WalkAreas(OVL_AREA* ovl, void (*rtn)(section*));

static void WalkSections(section* sect, void (*rtn)(section*))
{
    for (; sect != NULL; sect = sect->next_sect) {
        rtn(sect);
        WalkAreas(sect->areas, rtn);
    }
}

void WalkAreas(OVL_AREA* ovl, void (*rtn)(section*))
{
    for (; ovl != NULL; ovl = ovl->next_area) {
        WalkSections(ovl->sections, rtn);
    }
}

void FreeOvlStruct(void)
{
    OvlClasses = NULL;
    OvlVectors = NULL;
    if (OvlSeg != NULL) {
        FreeLeader(OvlSeg);
    }
    FreeDistStuff();
}
