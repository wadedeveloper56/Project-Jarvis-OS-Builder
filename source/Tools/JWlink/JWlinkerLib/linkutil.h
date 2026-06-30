#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

void FreeList(MemorySubsystem *memorySubsystem, void* _curr);
void LinkList(void* in_head, void* newnode);
char* ChkStrDup(MemorySubsystem *memorySubsystem, char* str);
char* ChkToString(MemorySubsystem *memorySubsystem, void* mem, unsigned len);
