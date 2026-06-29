#include "pch.h"
#include "objnode.h"
#include "carve.h"
#include "Structs.h"
#include "globals.h"
#include "permdata.h"

void FreeModEntry(mod_entry* mod)
{
    CarveFree(CarveModEntry, mod);
}

void FreeSegData(void* sdata)
{
    CarveFree(CarveSegData, sdata);
}
