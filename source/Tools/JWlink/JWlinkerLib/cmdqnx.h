#pragma once

#include <memory>
#include "cmd16m.h"
#include "MemorySubsystem.h"
#include "globals.h"
#include "Structs.h"
#include "cmdline.h"

using namespace std;

void ChkBase(offset align);
void SetQNXFmt(MemorySubsystem *memorySubsystem);
void FreeQNXFmt(MemorySubsystem *memorySubsystem);
