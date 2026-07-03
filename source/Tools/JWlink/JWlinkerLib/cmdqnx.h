#pragma once

#include "cmd16m.h"
#include "MemorySubsystem.h"
#include "globals.h"
#include "Structs.h"
#include "cmdline.h"
#include "MessagingSubsystem.h"

using namespace std;

void ChkBase(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem, offset align);
void SetQNXFmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem);
void FreeQNXFmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem);
