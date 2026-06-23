#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

void InitCmdFile(void);
char* GetNextLink(void);
void CleanSystemList(shared_ptr<MemorySubsystem> memory, bool check);
void PruneSystemList(shared_ptr<MemorySubsystem> memory);
void BurnSystemList(shared_ptr<MemorySubsystem> memory);
void FreePaths(shared_ptr<MemorySubsystem> memory);
