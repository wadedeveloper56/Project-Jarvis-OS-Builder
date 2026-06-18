#pragma once

#include "globals.h"

extern uint32_t  DbgInfoCount;
extern uint32_t  DbgInfoLen;
extern virt_mem  NovDbgInfo;
extern virt_mem  CurrDbgLoc;

void ResetLoadNov();
