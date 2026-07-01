#pragma once

#include "Structs.h"
#include "MemorySubsystem.h"

void WipeSym(MemorySubsystem* memorySubsystem, symbol* sym);
void FreeSymbol(MemorySubsystem* memorySubsystem, symbol* sym);
void CleanSym(MemorySubsystem* memorySubsystem);
