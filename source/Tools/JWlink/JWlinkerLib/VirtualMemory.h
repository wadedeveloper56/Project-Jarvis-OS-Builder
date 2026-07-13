#pragma once

#include "MemorySubsystem.h"

using namespace std;

class VirtualMemory
{
    MemorySubsystem *memorySubsystem;
public:
    VirtualMemory() { memorySubsystem = nullptr; }
	VirtualMemory(MemorySubsystem *memorySubsystem);
	~VirtualMemory();
};

