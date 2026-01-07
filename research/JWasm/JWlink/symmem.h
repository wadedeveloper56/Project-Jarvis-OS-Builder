#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"

void* Pass1Alloc(MemorySubsystem* memory, MessagingSubsystem* msg, size_t size);
void* PermAlloc(MemorySubsystem* memory, MessagingSubsystem* msg, size_t size);

