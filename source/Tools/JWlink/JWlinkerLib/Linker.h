#pragma once

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
#include "TempFileSubsystem.h"

typedef unsigned long stateflag;

using namespace std;

class Linker
{
	int argc;
	char** argv;
	stateflag LinkState;
	MemorySubsystem *memorySubsystem;
	FileSubsystem *fileSubsystem;
	MessagingSubsystem *messagingSubsystem;
	TokenBuffer *tokenBuffer;
	SpillFile *spillFile;
	SymbolTable *symbolTable;
	Orl *orl;
	VirtualMemory *virtualMemory;
	TempFileSubsystem* tempFileSubsystem;
public:
	Linker(int argc, char** argv);
	~Linker();
	int link();
private:
	void DoLink();
	void ResetSubSystems();
	void* MakeArray(unsigned size);
	void InitNodes(void);
	void BurnNodeArray(nodearray* list);
	void BurnNodes(void);
};

