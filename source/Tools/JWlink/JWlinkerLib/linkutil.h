#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

void FreeList(MemorySubsystem *memorySubsystem, void* _curr);
void LinkList(void* in_head, void* newnode);
char* ChkStrDup(MemorySubsystem *memorySubsystem, char* str);
char* ChkToString(MemorySubsystem *memorySubsystem, void* mem, unsigned len);
uint16_t blog_32(uint32_t value);
group_entry* FindGroup(segment seg);
offset FindLinearAddr(targ_addr* addr);
offset FindLinearAddr2(targ_addr* addr);
void WriteStdOut(char* str);
void WriteNLStdOut(void);
void WriteInfoStdOut(char* str, unsigned level, char* sym);
