#pragma once

#include <memory>
#include "MemorySubsystem.h"

using namespace std;

void SetELFFmt(void);
void FreeELFFmt(shared_ptr<MemorySubsystem> memorySubsystem);
