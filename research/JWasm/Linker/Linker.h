#pragma once

#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "Node.h"
#include "TokenBuffer.h"
#include "SpillFile.h"
#include "SymbolTable.h"
#include "ObjOrl.h"
#include "CmdLine.h"
#include "PermData.h"

class Linker
{
	MemorySubsystem* memory;
	FileSubsystem* file;
	MessagingSubsystem* messaging;
	Node* nodes;
	TokenBuffer* tokenBuffer;
	SpillFile* spillFile;
	SymbolTable* symbolTable;
	ObjOrl* objorl;
	CmdLine* cmdLine;
	PermData* permData;
public:
	Linker();
	~Linker();
	void mainLine();
private:
	void ResetSubSystems(void);
	void CleanSubSystems();
};

