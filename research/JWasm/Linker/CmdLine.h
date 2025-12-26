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
	parse_entry   FormatHelp[11];
	char* Name;
	sysblock* PrevCommand;
	sysblock* SysBlocks;
	file_defext     Extension;
	file_list** CurrFList;
	tok             Token;
	commandflag     CmdFlags;
public:
	CmdLine(MemorySubsystem* memory, MessagingSubsystem* msg, PermData* permData);
	~CmdLine();
	void BurnSystemList(void);
	void FreePaths(void);
	void FreeFormatStuff(void);
	void DoCmdFile(char* fname);
private:
	void CleanSystemList(bool check);
	void ResetCmdFile(void);
	void SetSegMask(void);
	void GetCmdLine(char* buff);
	int _bgetcmd(char* buffer, int len);
	char* getcmd(char* buffer);
	void NewCommandSource(char* name, char* buff, method how);
	bool IsStdOutConsole(void);
};

