#pragma once

#include <memory>
#include "cmd16m.h"
#include "MemorySubsystem.h"
#include "globals.h"
#include "Structs.h"
#include "cmdline.h"

using namespace std;

void ChkBase(offset align);
void SetQNXFmt(shared_ptr<MemorySubsystem> memorySubsystem);
void FreeQNXFmt(shared_ptr<MemorySubsystem> memorySubsystem);
