#include "pch.h"
#include "obj2supp.h"
#include "globals.h"
#include "Structs.h"

offset           LastOptimized;  // offset last optimized.
fix_type         LastOptType;
segdata* LastSegData;
offset           FixupOverflow;

void ResetObj2Supp()
{
    FixupOverflow = 0;
    LastOptType = (fix_type)0;
    LastOptimized = 0xFFFFFFFF;
}