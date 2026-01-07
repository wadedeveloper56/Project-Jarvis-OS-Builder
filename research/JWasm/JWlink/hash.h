#pragma once

#include "globals.h"

unsigned StringiHashFunc(void* _s, unsigned size);
pHTable CreateHTable(int size, pHashFunc hashFunc, pHashElemCmp compareFunc);