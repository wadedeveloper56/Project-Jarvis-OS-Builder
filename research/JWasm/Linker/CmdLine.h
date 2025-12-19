#pragma once

#include "globals.h"
#include "MemorySubsystem.h"

class CmdLine
{
	MemorySubsystem* memory;
	char* Name;
	sysblock* PrevCommand;
	sysblock* SysBlocks;
public:
	CmdLine(MemorySubsystem* memory);
	~CmdLine();
	void BurnSystemList(void);
	void FreePaths(void);
private:
	void CleanSystemList(bool check);
};

