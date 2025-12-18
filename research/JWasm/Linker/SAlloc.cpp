#include "pch.h"
#include "globals.h"
#include "SAlloc.h"

void ResetAddr(void)
{
    CurrLoc.seg = 0;
    CurrLoc.off = 0;
    CurrentSeg = NULL;
}
