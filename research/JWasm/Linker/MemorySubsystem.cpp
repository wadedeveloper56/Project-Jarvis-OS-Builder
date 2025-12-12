#include "MemorySubsystem.h"
#include "Memory.h"

MemorySubsystem::MemorySubsystem()
{
}

MemorySubsystem::~MemorySubsystem()
{
}

template <typename T> T MemorySubsystem::AllocateMemory(size_t size)
{
	return static_cast<T>(AllocateMemory(size));
}

template <typename T> void MemorySubsystem::FreeMemory(T memoryBlock)
{
	FreeMemory(memoryBlock);
}

template <typename T> T MemorySubsystem::ReallocateMemory(void* memblock, size_t size)
{
	return static_cast<T*>(ReallocateMemory(memblock, size));
}	

template <typename T> T MemorySubsystem::ExpandMemory(void* memblock, size_t size)
{
	return static_cast<T*>(ExpandMemory(memblock, size));
}