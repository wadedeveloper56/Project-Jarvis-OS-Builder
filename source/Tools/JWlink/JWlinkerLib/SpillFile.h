#pragma once

#include "MemorySubsystem.h"
#include "File.h"
#include "Structs.h"
#include "FileSubsystem.h"

class SpillFile
{
	MemorySubsystem *memorySubsystem;
	FileSubsystem *fileSubsystem;
public:
	SpillFile(MemorySubsystem *memorySubsystem, FileSubsystem *fileSubsystem);
	~SpillFile();
};

