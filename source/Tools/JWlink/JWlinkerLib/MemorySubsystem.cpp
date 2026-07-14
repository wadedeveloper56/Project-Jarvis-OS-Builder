#include "pch.h"
#include "MemorySubsystem.h"
#include "debug.h"

MemorySubsystem::MemorySubsystem()
{
	DEBUG((DBG_OLD, "MemorySubsystem constructor\n"));
}

MemorySubsystem::~MemorySubsystem() 
{
	DEBUG((DBG_OLD, "MemorySubsystem destructor\n"));
}

void* MemorySubsystem::AllocateMemory(size_t size) { return ::AllocateMemory(size); }

void MemorySubsystem::FreeMemory(void* memoryBlock) { ::FreeMemory(memoryBlock); }

void* MemorySubsystem::ReallocateMemory(void* memblock, size_t size) { return ::ReallocateMemory(memblock, size); }
