#include "MemorySubsystem.h"
#include "Memory.h"

MemorySubsystem::MemorySubsystem()
{
}

MemorySubsystem::~MemorySubsystem()
{
}

void* MemorySubsystem::AllocateMemory(size_t size)
{
	return ::AllocateMemory(size);
}

void MemorySubsystem::FreeMemory(void* memoryBlock)
{
	::FreeMemory(memoryBlock);
}

void* MemorySubsystem::ReallocateMemory(void* memblock, size_t size)
{
	return ::ReallocateMemory(memblock, size);
}	

void* MemorySubsystem::ExpandMemory(void* memblock, size_t size)
{
	return ::ExpandMemory(memblock, size);
}