#include "pch.h"
#include "globals.h"
#include "overlays.h"
#include "ovlsupp.h"

void WalkAllSects(void (*rtn)(section*))
{
    rtn(Root);
    if (FmtData.type & MK_OVERLAYS) {
        WalkAreas(Root->areas, rtn);
    }
}