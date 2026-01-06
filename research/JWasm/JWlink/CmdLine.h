#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"
#include "CmdPlatform.h"

#define IS_WHITESPACE(ptr) (*(ptr) == ' ' || *(ptr) =='\t' || *(ptr) == '\r')
#define NLCHAR         '\n'
#define CTRLZ          '\32'

typedef struct _select_format {
	exe_format bits;
	char* lib_var_name;
	CmdPlatform* platform;
}select_format;

class CmdLine
{
	MemorySubsystem* memory;
	MessagingSubsystem* msg;
	select_format PossibleFmt[11];
	parse_entry   FormatHelp[11];
public:
	CmdLine(MemorySubsystem* memory, MessagingSubsystem* msg);
	~CmdLine();
	select_format* getPossibleFormat(int i) { return &PossibleFmt[i]; }
};

