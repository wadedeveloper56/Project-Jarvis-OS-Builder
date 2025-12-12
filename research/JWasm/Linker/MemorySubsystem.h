#pragma once

class MemorySubsystem
{
public:
	MemorySubsystem();
	~MemorySubsystem();
	void* AllocateMemory(size_t size);
	void FreeMemory(void* memoryBlock);
	void* ReallocateMemory(void* memblock, size_t size);
	void* ExpandMemory(void* memblock, size_t size);
};

