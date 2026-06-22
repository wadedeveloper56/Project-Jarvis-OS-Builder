#pragma once

#include <memory>
#include "MemorySubsystem.h"

using namespace std;

void ResetSymTrace();
void CleanTraces(shared_ptr<MemorySubsystem> memorySubsystem);