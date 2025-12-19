#pragma once

#include "types.h"
#include "MemorySubsystem.h"

bool TestBit(int_8* array, unsigned num);
void FreeList(MemorySubsystem* memory, void* _curr);
