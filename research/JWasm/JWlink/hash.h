#pragma once

#include "globals.h"
#include "MemorySubsystem.h"

unsigned StringiHashFunc(void* _s, unsigned size);
pHTable CreateHTable(MemorySubsystem* memory, int size, pHashFunc hashFunc, pHashElemCmp compareFunc);