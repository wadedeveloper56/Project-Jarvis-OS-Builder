#include "pch.h"
#include "objpass1.h"
#include "Structs.h"
#include "globals.h"
#include "ring.h"
#include "carve.h"
#include "permdata.h"
#include "objnode.h"

void ResetObjPass1()
{
    ObjFormat = (obj_format)0;
}

void FreeLeader(void* seg)
{
    RingWalk(((seg_leader*)seg)->pieces, FreeSegData);
    CarveFree(CarveLeader, seg);
}
