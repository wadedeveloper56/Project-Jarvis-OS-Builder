#include "pch.h"
#include "LinkerMemory.h"

LinkerMemory::LinkerMemory()
{
}

LinkerMemory::~LinkerMemory() 
{
}

void* LinkerMemory::alloc(uint64_t size) 
{
	return malloc((size_t)size);
}

void LinkerMemory::free(void* mem) 
{
	::free(mem);
}
