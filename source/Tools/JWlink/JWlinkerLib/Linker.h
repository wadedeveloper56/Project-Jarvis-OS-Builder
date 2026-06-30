#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "TokenBuffer.h"
#include "File.h"
#include "SpillFile.h"
#include "SymbolTable.h"
#include "orl.h"
#include "Orl2.h"
#include "VirtualMemory.h"

typedef unsigned long stateflag;

using namespace std;

class Linker
{
	int argc;
	char** argv;
	stateflag LinkState;
	char* ArgSave;
	void* SpawnStack;
	MemorySubsystem *memorySubsystem;
	FileSubsystem *fileSubsystem;
	MessagingSubsystem *messagingSubsystem;
	TokenBuffer *tokenBuffer;
	SpillFile *spillFile;
	SymbolTable *symbolTable;
	Orl *orl;
	VirtualMemory *virtualMemory;
public:
	Linker(int argc, char** argv);
	~Linker();
	int link(char* cmds);
	int Spawn(void (Linker::*fn)(void));
	void LinkMeBaby(void);
	void CleanSubSystems(void);
	void ResetSubSystems(void);
	void DoLink(char* cmdline);
	void ResetMisc(void);
};

