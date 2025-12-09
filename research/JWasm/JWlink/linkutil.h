#pragma once

#include "globals.h"

unsigned_16 blog_32(unsigned_32 value);
group_entry* FindGroup(segment seg);
offset FindLinearAddr(targ_addr* addr);
offset FindLinearAddr2(targ_addr* addr);
bool TestBit(byte* array, unsigned num);
