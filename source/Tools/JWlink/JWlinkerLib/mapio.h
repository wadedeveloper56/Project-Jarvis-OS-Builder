#pragma once

#include <memory>
#include "MemorySubsystem.h"

using namespace std;

void ResetMapIO();
void FreeUndefs();
void FreeUndefs(shared_ptr<MemorySubsystem> memorySubsystem);
