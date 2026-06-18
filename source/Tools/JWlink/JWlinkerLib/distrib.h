#pragma once

#include "Structs.h"

extern uint16_t  CurrModThere;
extern arcdata* ArcBuffer;
extern uint32_t  ArcBufLen;
extern mod_entry** ModTable;
extern uint16_t  CurrModHandle;
extern section** SectOvlTab;

void ResetDistrib();