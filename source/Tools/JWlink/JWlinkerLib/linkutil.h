#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

void FreeList(shared_ptr<MemorySubsystem> memorySubsystem, void* _curr);
void LinkList(void* in_head, void* newnode);
char* ChkStrDup(shared_ptr<MemorySubsystem> memorySubsystem, char* str);
char* ChkToString(shared_ptr<MemorySubsystem> memorySubsystem, void* mem, unsigned len);
