#pragma once

#include "globals.h"
#include "MemorySubsystem.h"

bool TestBit(int_8* array, unsigned num);
void FreeList(MemorySubsystem* memory, void* _curr);
void WalkSections(MemorySubsystem* memory, section* sect, void (*rtn)(MemorySubsystem*, section*));
void WalkAreas(MemorySubsystem* memory, OVL_AREA* ovl, void (*rtn)(MemorySubsystem*, section*));
void WalkAllSects(MemorySubsystem* memory, void (*rtn)(MemorySubsystem*, section*));
