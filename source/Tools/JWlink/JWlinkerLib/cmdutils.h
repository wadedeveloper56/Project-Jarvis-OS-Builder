#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

section* NewSection(MemorySubsystem *memorySubsystem);
char* FileName(MemorySubsystem *memorySubsystem,char* buff, unsigned len, file_defext etype, bool force);
