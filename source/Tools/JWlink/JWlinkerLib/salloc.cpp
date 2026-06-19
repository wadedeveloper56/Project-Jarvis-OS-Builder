#include "pch.h"
#include "salloc.h"
#include "Structs.h"
#include "globals.h"

targ_addr    DataLoc;
static targ_addr    CodeLoc;

void ResetAddr()
{
    CurrLoc.seg = 0;
    CurrLoc.off = 0;
    CurrentSeg = NULL;
}