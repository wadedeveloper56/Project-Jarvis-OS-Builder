#pragma once

#include "globals.h"
#include "MemorySubsystem.h"

void SetLibCase(void);
void FreeDictCache(MemorySubsystem* memory, void** cache, unsigned_16 buckets);
