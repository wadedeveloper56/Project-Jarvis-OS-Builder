#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

section* NewSection(shared_ptr<MemorySubsystem> memorySubsystem);
