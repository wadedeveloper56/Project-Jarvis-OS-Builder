#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"
#include "CmdPlatform.h"
#include "PermData.h"

typedef struct _select_format {
	exe_format bits;
	char* lib_var_name;
	CmdPlatform* platform;
}select_format;

class CmdLine
{
	MemorySubsystem* memory;
	MessagingSubsystem* msg;
	PermData* permData;
	select_format PossibleFmt[11];
	char* Name;
	sysblock* PrevCommand;
	sysblock* SysBlocks;
public:
	CmdLine(MemorySubsystem* memory, MessagingSubsystem* msg, PermData* permData);
	~CmdLine();
	void BurnSystemList(void);
	void FreePaths(void);
	void FreeFormatStuff(void);
private:
	void CleanSystemList(bool check);
};

