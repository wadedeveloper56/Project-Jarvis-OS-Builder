#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

extern uint16_t  CurrModThere;
extern arcdata* ArcBuffer;
extern uint32_t  ArcBufLen;
extern mod_entry** ModTable;
extern uint16_t  CurrModHandle;
extern section** SectOvlTab;

void ResetDistrib();
void FreeDistStuff(shared_ptr<MemorySubsystem> memorySubsystem);
