#include "pch.h"
#include "globals.h"
#include "objpass1.h"
#include "ring.h"
#include "carve.h"
#include "permdata.h"
#include "objnode.h"

void ResetObjPass1(void)
{
    ObjFormat = (obj_format)0;
}

void FreeLeader(void* seg)
{
    RingWalk(((seg_leader*)seg)->pieces, FreeSegData);
    CarveFree(CarveLeader, seg);
}
