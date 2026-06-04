#pragma once

#include "Memory.h"

class MemorySubsystem
{
public:
	MemorySubsystem();
	~MemorySubsystem();
	void* AllocateMemory(size_t size);
	void FreeMemory(void* memoryBlock);
	void* ReallocateMemory(void* memblock, size_t size);
};

