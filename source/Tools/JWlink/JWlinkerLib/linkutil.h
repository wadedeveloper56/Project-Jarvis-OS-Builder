#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

void FreeList(shared_ptr<MemorySubsystem> memorySubsystem, void* _curr);
void LinkList(void* in_head, void* newnode);
