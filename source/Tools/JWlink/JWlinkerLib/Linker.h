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
	shared_ptr<MemorySubsystem> memorySubsystem;
	shared_ptr<FileSubsystem> fileSubsystem;
	shared_ptr<MessagingSubsystem> messagingSubsystem;
	shared_ptr<TokenBuffer> tokenBuffer;
	shared_ptr<SpillFile> spillFile;
	shared_ptr<SymbolTable> symbolTable;
	shared_ptr<Orl> orl;
	shared_ptr<VirtualMemory> virtualMemory;
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

