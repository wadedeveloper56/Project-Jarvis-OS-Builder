#pragma once

class MemorySubsystem
{
public:
	MemorySubsystem();
	~MemorySubsystem();
	template <typename T> T AllocateMemory(size_t size);
	template <typename T> void FreeMemory(T memoryBlock);
	template <typename T> T ReallocateMemory(void* memblock, size_t size);
	template <typename T> T ExpandMemory(void* memblock, size_t size);

};

