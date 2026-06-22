#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "File.h"
#include "Structs.h"

class SpillFile
{
	shared_ptr<MemorySubsystem> memorySubsystem;
	f_handle TempFile;
	char* TFileName;
	unsigned long long TmpFSize;
public:
	SpillFile(shared_ptr<MemorySubsystem> memorySubsystem);
	~SpillFile(void);
	void CloseSpillFile(void);
};

