#pragma once

#include "carve.h"
#include "Structs.h"
#include "globals.h"
#include "permdata.h"
#include "ObjectNode.h"

void FreeModEntry(mod_entry* mod);
void FreeSegData(void* sdata);
void FreeNodes(nodearray* nodes);
