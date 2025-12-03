#include "pch.h"
#include "framework.h"

void* AllocateMemory(size_t size)
{
	return malloc(size);
}

void FreeMemory(void* memoryBlock)
{
	free(memoryBlock);
}

void* ReallocateMemory(void* memblock, size_t size)
{
	return realloc(memblock, size);
}