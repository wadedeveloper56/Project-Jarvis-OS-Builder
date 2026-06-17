#pragma once

#include <memory>
#include "Structs.h"
#include "MemorySubsystem.h"

using namespace std;

carve_t CarveCreate(shared_ptr<MemorySubsystem> memorySubsystem, size_t elm_size, size_t blk_size);
