#pragma once

#include <memory>
#include "MemorySubsystem.h"

using namespace std;

void SetELFFmt(shared_ptr<MemorySubsystem> memorySubsystem);
void FreeELFFmt(shared_ptr<MemorySubsystem> memorySubsystem);
