#pragma once

#include <memory>
#include "Structs.h"
#include "MemorySubsystem.h"

using namespace std;

void InitStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, bool dontsplit);
