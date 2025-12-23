#pragma once

#include "objfree.h"
#include "SymbolTableMemory.h"
#include "MixCache.h"

void ResetDistrib(void);
void FreeDistStuff(MemorySubsystem* memory, PermData* permData, MixCache* cache, SymbolTableMemory* symMem);
