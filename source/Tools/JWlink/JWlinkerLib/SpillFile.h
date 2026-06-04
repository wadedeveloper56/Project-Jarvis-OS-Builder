#pragma once

#include "File.h"

class SpillFile
{
	f_handle TempFile;
	char* TFileName;
	unsigned long long TmpFSize;
public:
	SpillFile(void);
	~SpillFile(void);
};

