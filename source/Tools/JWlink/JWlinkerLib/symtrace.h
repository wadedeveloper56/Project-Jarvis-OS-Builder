#pragma once

#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"
#include "SpillFile.h"

using namespace std;

void ResetSymTrace();
void CleanTraces(MemorySubsystem *memorySubsystem);
void CheckTraces(MemorySubsystem* memorySubsystem, SpillFile* spillFile, MessagingSubsystem* messagingSubsystem);
void CheckFileTrace(MemorySubsystem* memorySubsystem, SpillFile* spillFile, section* sect);
