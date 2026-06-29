#include "pch.h"
#include "ovlsupp.h"
#include "MemorySubsystem.h"
#include "objfree.h"
#include "ObjectNode.h"
#include "ObjORL.h"
#include "globals.h"
#include "debug.h"
#include "objio.h"
#include "Structs.h"
#include "linkutil.h"
#include "objcache.h"
#include "objnode.h"
#include "dbgall.h"
#include "libr.h"
#include "reloc.h"
#include "hash.h"
#include "ring.h"
#include "objpass1.h"
#include "distrib.h"
#include "spillfile.h"

using namespace std;

uint16_t         AreaSize;

void ResetOvlSupp()
{
    AreaSize = 0xFFFF;
}

void FreeOvlStruct(shared_ptr<MemorySubsystem> memorySubsystem)
{
    OvlClasses = NULL;
    OvlVectors = NULL;
    if (OvlSeg != NULL)
    {
        FreeLeader(OvlSeg);
    }
    FreeDistStuff(memorySubsystem);
}

void WalkSections(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, section* sect, void (*rtn)(shared_ptr<MemorySubsystem>, shared_ptr<SpillFile>,section*))
{
    for (; sect != NULL; sect = sect->next_sect)
    {
        rtn(memorySubsystem, spillFile, sect);
        WalkAreas(memorySubsystem, spillFile, sect->areas, rtn);
    }
}

void WalkAreas(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, OVL_AREA* ovl, void (*rtn)(shared_ptr<MemorySubsystem>, shared_ptr<SpillFile>,section*))
{
    for (; ovl != NULL; ovl = ovl->next_area)
    {
        WalkSections(memorySubsystem, spillFile, ovl->sections, rtn);
    }
}