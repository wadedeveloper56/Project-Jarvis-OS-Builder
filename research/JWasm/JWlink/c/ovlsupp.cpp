#include "pch.h"
#include "globals.h"
#include "ovlsupp.h"
#include "objpass1.h"
#include "distrib.h"

unsigned_16         AreaSize;

void ResetOvlSupp(void)
{
    AreaSize = 0xFFFF;
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
