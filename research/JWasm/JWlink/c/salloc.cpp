#include "pch.h"
#include "globals.h"
#include "salloc.h"

static targ_addr    DataLoc;
static targ_addr    CodeLoc;

void ResetAddr(void)
{
    CurrLoc.seg = 0;
    CurrLoc.off = 0;
    CurrentSeg = nullptr;
}