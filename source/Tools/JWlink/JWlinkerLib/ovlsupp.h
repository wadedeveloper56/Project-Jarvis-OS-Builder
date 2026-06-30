#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"
#include "SpillFile.h"

using namespace std;

void ResetOvlSupp();
void FreeOvlStruct(MemorySubsystem *memorySubsystem);
void WalkSections(MemorySubsystem *memorySubsystem, SpillFile * spillFile, section* sect, void (*rtn)(MemorySubsystem *, SpillFile *, section*));
void WalkAreas(MemorySubsystem *memorySubsystem, SpillFile * spillFile, OVL_AREA* ovl, void (*rtn)(MemorySubsystem *, SpillFile *, section*));

