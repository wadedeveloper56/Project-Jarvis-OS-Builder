#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

section* NewSection(shared_ptr<MemorySubsystem> memorySubsystem);
char* FileName(shared_ptr<MemorySubsystem> memorySubsystem,char* buff, unsigned len, file_defext etype, bool force);
