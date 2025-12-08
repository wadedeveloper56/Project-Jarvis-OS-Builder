#include "pch.h"
#include "globals.h"
#include "carve.h"
#include "ring.h"
#include "objnode.h"
#include "permdata.h"

void FreeLeader(void* seg)
{
    RingWalk(((seg_leader*)seg)->pieces, FreeSegData);
    CarveFree(CarveLeader, seg);
}