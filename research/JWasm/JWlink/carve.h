#pragma once

#include "globals.h"
#include "MemorySubsystem.h"

void DbgZapAlloc(void* tgt, size_t size);
void DbgZapFreed(void* tgt, size_t size);
void CarveFree(carve_t cv, void* elm);
void* CarveAlloc(MemorySubsystem* memory, carve_t cv);
carve_t CarveCreate(MemorySubsystem* memory, size_t elm_size, size_t blk_size);
