#pragma once

#include <memory>
#include "MemorySubsystem.h"
using namespace std;

void SetLibCase();
void BurnLibs(shared_ptr<MemorySubsystem> memorySubsystem);
void FreeDictCache(shared_ptr<MemorySubsystem> memorySubsystem, void** cache, uint16_t buckets);

