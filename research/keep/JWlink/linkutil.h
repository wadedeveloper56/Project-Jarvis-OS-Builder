#pragma once

#include "objstruct.h"
#include "globals.h"

group_entry* FindGroup(segment seg);
offset FindLinearAddr(targ_addr* addr);
offset FindLinearAddr2(targ_addr* addr);
unsigned_16 blog_32(unsigned_32 value);
int Spawn(void (*fn)(void));
void Suicide(void);
void WriteStdOut(char* str);
void WriteNLStdOut(void);
bool TestBit(byte* array, unsigned num);
void WriteInfoStdOut(char* str, unsigned level, char* sym);
void FreeList(void* _curr);
void LnkFatal(char* msg);
