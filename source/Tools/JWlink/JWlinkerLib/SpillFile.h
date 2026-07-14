#pragma once

#include "MemorySubsystem.h"
#include "File.h"
#include "Structs.h"
#include "TempFileSubsystem.h"

class SpillFile
{
	MemorySubsystem *memorySubsystem;
	TempFileSubsystem * TempFile;
	char* TFileName;
	unsigned long    TmpFSize;
public:
	SpillFile(MemorySubsystem *memorySubsystem);
	~SpillFile();
};

