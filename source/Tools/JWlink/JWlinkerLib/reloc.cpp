#include "pch.h"
#include "reloc.h"
#include "Structs.h"

unsigned        FmtRelocSize;
reloc_info* FloatFixups;

void ResetReloc()
{
    FloatFixups = NULL;
}