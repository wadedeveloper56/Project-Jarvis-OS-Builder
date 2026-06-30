#pragma once

#include <memory>
#include "MemorySubsystem.h"
using namespace std;

void SetLibCase();
void BurnLibs(MemorySubsystem *memorySubsystem);
void FreeDictCache(MemorySubsystem *memorySubsystem, void** cache, uint16_t buckets);

