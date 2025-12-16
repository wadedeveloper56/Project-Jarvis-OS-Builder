#pragma once

#include "FileSubsystem.h"

class SpillFile
{
	FileSubsystem* file;
	char* TFileName;
	unsigned long TmpFSize;
public:
	SpillFile(FileSubsystem* file);
	~SpillFile();
};

