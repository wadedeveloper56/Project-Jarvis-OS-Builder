#pragma once

#include "globals.h"
#include "FileSubsystem.h"

void DbgZapAlloc(void* tgt, size_t size);
void DbgZapFreed(void* tgt, size_t size);
void CarveFree(carve_t cv, void* elm);
void* CarveAlloc(carve_t cv);
carve_t CarveCreate(size_t elm_size, size_t blk_size);
void CarveDestroy(carve_t cv);
void CarveVerifyAllGone(carve_t cv, char* node_name);
