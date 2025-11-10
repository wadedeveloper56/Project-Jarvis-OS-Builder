#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "library.h"
#include "virtmem.h"
#include "reloc.h"
#include "objcache.h"
#include "alloc.h"

void LnkMemInit(void)
{
}

void LnkMemFini(void)
{
}

void* LnkExpand(void* src, size_t size)
{
	return NULL;
}

void* LAlloc(size_t size)
{
	return NULL;
}

void* ChkLAlloc(size_t size)
{
	return NULL;
}

void LFree(void* p)
{
}
