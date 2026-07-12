#include "pch.h"
#include "overlays.h"
#include "globals.h"
#include "Structs.h"
#include "ovlsupp.h"
#include "MemorySubsystem.h"
#include "SpillFile.h"
#include "distrib.h"

using namespace std;

void WalkAllOvl(MemorySubsystem* memorySubsystem, SpillFile* spillFile, void (*rtn)(MemorySubsystem*, SpillFile*, section*))
{
    if (FmtData.type & MK_OVERLAYS)
    {
        WalkAreas(memorySubsystem, spillFile, Root->areas, rtn);
    }
}

void NumASect(MemorySubsystem* memorySubsystem, SpillFile* spillFile, section* sect)
{
    if (FmtData.u.dos.distribute)
    {
        SectOvlTab[OvlNum] = sect;
    }
    sect->ovl_num = OvlNum++;
}

void NumberSections(MemorySubsystem* memorySubsystem, SpillFile* spillFile)
{
    if ((FmtData.type & MK_OVERLAYS) && FmtData.u.dos.distribute)
    {
        _LnkAlloc(section**, SectOvlTab, sizeof(section*) * (OvlNum + 1));
        SectOvlTab[0] = Root;
    }
    OvlNum = 1;
    WalkAllOvl(memorySubsystem, spillFile, &NumASect);
}