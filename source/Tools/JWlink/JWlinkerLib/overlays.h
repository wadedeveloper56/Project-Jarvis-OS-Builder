#pragma once

#include "MemorySubsystem.h"
#include "SpillFile.h"
#include "distrib.h"

void WalkAllOvl(MemorySubsystem* memorySubsystem, SpillFile* spillFile, void (*rtn)(MemorySubsystem*, SpillFile*, section*));
void NumASect(MemorySubsystem* memorySubsystem, SpillFile* spillFile, section* sect);
void NumberSections(MemorySubsystem* memorySubsystem, SpillFile* spillFile);
