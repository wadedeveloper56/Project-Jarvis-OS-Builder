#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"

using namespace std;

void SetELFFmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem);
void FreeELFFmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem);
