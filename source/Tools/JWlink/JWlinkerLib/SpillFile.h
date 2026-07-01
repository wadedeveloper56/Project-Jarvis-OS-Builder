#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "File.h"
#include "Structs.h"
#include "FileSubsystem.h"

class SpillFile
{
	MemorySubsystem *memorySubsystem;
	FileSubsystem *fileSubsystem;
	f_handle TempFile;
	char* TFileName;
	unsigned long long TmpFSize;
public:
	SpillFile(MemorySubsystem *memorySubsystem, FileSubsystem *fileSubsystem);
	~SpillFile();
	void CloseSpillFile();
	char* MakeTempName(char* name);
	f_handle OpenTempFile(char** fname);
	unsigned long SpillAlloc(unsigned amt);
	void SpillWrite(unsigned long base, unsigned off, void* mem, unsigned size);
	void SpillRead(unsigned long base, unsigned off, void* mem, unsigned size);
};

