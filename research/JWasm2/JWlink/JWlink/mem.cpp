#include "pch.h"
#include "mem.h"
#include "TRMem.h"
#include "globals.h"

void LnkMemInit(void)
{
	trmem = new TRMem(_TRMEM_ALLOC_SIZE_0 | _TRMEM_REALLOC_SIZE_0 | _TRMEM_REALLOC_NULL | _TRMEM_FREE_NULL | _TRMEM_OUT_OF_MEMORY | _TRMEM_CLOSE_CHECK_FREE);
}

void LnkMemFini(void)
{
	delete trmem;
}
