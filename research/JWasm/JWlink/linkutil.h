#pragma once

#include "objstruct.h"
#include "globals.h"

group_entry* FindGroup(segment seg);
offset FindLinearAddr(targ_addr* addr);
offset FindLinearAddr2(targ_addr* addr);
unsigned_16 blog_32(unsigned_32 value);
void WriteStdOut(char* str);
void WriteNLStdOut(void);
