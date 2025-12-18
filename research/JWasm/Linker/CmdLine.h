#pragma once

#include "globals.h"
#include "MemorySubsystem.h"

class CmdLine
{
	MemorySubsystem* memory;
	sysblock* PrevCommand;
	sysblock* SysBlocks;
public:
	CmdLine(MemorySubsystem* memory);
	~CmdLine();
	void BurnSystemList(void);
private:
	void CleanSystemList(bool check);
};

