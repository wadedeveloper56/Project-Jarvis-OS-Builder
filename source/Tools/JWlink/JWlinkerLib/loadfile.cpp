#include "pch.h"
#include "loadfile.h"
#include "globals.h"
#include "Structs.h"

seg_leader* StackSegPtr;
startinfo       StartInfo;
implibinfo       ImpLib;

void ClearStartAddr()
{
    memset(&StartInfo, 0, sizeof(startinfo));
}

void ResetLoadFile()
{
    ClearStartAddr();
}

