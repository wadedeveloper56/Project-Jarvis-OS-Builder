#pragma once

#include "PermData.h"
#include "MemorySubsystem.h"
#include "SymbolTableMemory.h"
#include "MixCache.h"

void ResetOvlSupp(void);
void FreeOvlStruct(MemorySubsystem* memory, PermData* permData, MixCache* cache, SymbolTableMemory* symMem);
