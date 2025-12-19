#pragma once

#include "MemorySubsystem.h"

void CleanLinkStruct(MemorySubsystem* memory);
void FreeSegFlags(MemorySubsystem* memory, seg_flags* curr);
