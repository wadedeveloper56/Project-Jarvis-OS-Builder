#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"
#include "SpillFile.h"

using namespace std;

void ResetOvlSupp();
void FreeOvlStruct(shared_ptr<MemorySubsystem> memorySubsystem);
void WalkSections(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, section* sect, void (*rtn)(shared_ptr<MemorySubsystem>, shared_ptr<SpillFile>, section*));
void WalkAreas(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile, OVL_AREA* ovl, void (*rtn)(shared_ptr<MemorySubsystem>, shared_ptr<SpillFile>, section*));

