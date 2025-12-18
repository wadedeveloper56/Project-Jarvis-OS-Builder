#pragma once

#include "FileSubsystem.h"
#include "MemorySubsystem.h"

class SpillFile
{
	FileSubsystem* file;
	MemorySubsystem* memory;
	char* TFileName;
	unsigned long TmpFSize;
public:
	SpillFile(FileSubsystem* file, MemorySubsystem* memory);
	~SpillFile();
};

