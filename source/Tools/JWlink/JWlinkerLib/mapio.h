#pragma once

#include <memory>
#include "MemorySubsystem.h"

using namespace std;

void ResetMapIO();
void FreeUndefs();
void FreeUndefs(MemorySubsystem *memorySubsystem);
void BufWrite(char* buffer, int len);
void WriteMapNL(unsigned count);
