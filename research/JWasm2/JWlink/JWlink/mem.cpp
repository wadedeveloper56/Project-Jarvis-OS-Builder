#include "pch.h"
#include "mem.h"
#include "TRMem.h"
#include "globals.h"

void LFree(void* p)
{
	if (p == NULL) return;
	trmem->TRMemfree(p, TRMemWho());
}

void* LnkReAlloc(void* src, size_t size)
{
	void *dest = trmem->TRMemRealloc(src, size, TRMemWho());
	return(dest);
}

void* DoLAlloc(size_t size)
{
	void* p = trmem->alloc(size);
	if (p != NULL) {
		memset(p, 0, size);
	}
	return(p);
}

void* ChkLAlloc(size_t size)
{
	void* ptr = DoLAlloc(size);
	return(ptr);
}

void LnkMemInit(void)
{
	trmem = new TRMem(_TRMEM_ALLOC_SIZE_0 | _TRMEM_REALLOC_SIZE_0 | _TRMEM_REALLOC_NULL | _TRMEM_FREE_NULL | _TRMEM_OUT_OF_MEMORY | _TRMEM_CLOSE_CHECK_FREE);
}

void LnkMemFini(void)
{
	delete trmem;
}
