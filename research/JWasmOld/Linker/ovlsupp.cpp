#include "pch.h"
#include "ovlsupp.h"
#include "globals.h"
#include "ovlsupp.h"
#include "PermData.h"
#include "distrib.h"

unsigned_16         AreaSize;

void ResetOvlSupp(void)
{
	AreaSize = 0xFFFF;
}

void FreeOvlStruct(MemorySubsystem* memory, PermData* permData, MixCache* cache, SymbolTableMemory* symMem)
{
	OvlClasses = NULL;
	OvlVectors = NULL;
	if (OvlSeg != NULL) {
		permData->FreeLeader(OvlSeg);
	}
	FreeDistStuff(memory, permData, cache, symMem);
}