#pragma once

class MemorySubsystem
{
public:
	MemorySubsystem();
	~MemorySubsystem();
	static void* AllocateMemory(size_t size);
	static void FreeMemory(void* memoryBlock);
	void* ReallocateMemory(void* memblock, size_t size);
	void* ExpandMemory(void* memblock, size_t size);
};

