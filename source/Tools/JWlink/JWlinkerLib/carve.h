#pragma once

#include <memory>
#include "Structs.h"
#include "MemorySubsystem.h"

using namespace std;

carve_t CarveCreate(MemorySubsystem *memorySubsystem, size_t elm_size, size_t blk_size);
void CarveFree(carve_t cv, void* elm);
void CarveDestroy(MemorySubsystem *memorySubsystem, carve_t cv);
#ifndef NDEBUG
void CarveVerifyAllGone(carve_t cv, char* node_name);
#endif

