#include "pch.h"
#include "VirtualMemory.h"
#include "MemorySubsystem.h"
#include "debug.h"

using namespace std;

VirtualMemory::VirtualMemory(MemorySubsystem *memorySubsystem)
{
	DEBUG((DBG_OLD, "VirtualMemory constructor\n"));
	this->memorySubsystem = memorySubsystem;
}

VirtualMemory::~VirtualMemory()
{
	DEBUG((DBG_OLD, "VirtualMemory destructor\n"));
}

