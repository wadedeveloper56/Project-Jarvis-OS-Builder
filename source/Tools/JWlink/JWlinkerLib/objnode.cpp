#include "pch.h"
#include "objnode.h"
#include "carve.h"
#include "Structs.h"
#include "globals.h"
#include "permdata.h"
#include "ObjectNode.h"

void FreeModEntry(mod_entry* mod)
{
    CarveFree(CarveModEntry, mod);
}

void FreeSegData(void* sdata)
{
    CarveFree(CarveSegData, sdata);
}

void FreeNodes(nodearray* nodes)
{
    unsigned    index;

    for (index = 0; index <= nodes->arraymax; index++)
    {
        memset(nodes->array[index], 0, nodes->elsize * NODE_ARRAY_SIZE);
    }
    nodes->num = 0;
}
