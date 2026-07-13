#include "pch.h"
#include "Linker.h"
#include "debug.h"
#include "orl.h"
#include "Memory.h"
#include "Orl2.h"
#include "VirtualMemory.h"
#include "SpillFile.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "TokenBuffer.h"
#include "SymbolTable.h"

Linker::Linker(int argc, char** argv)
{
	this->argc = argc;
	this->argv = argv;
	memorySubsystem = new MemorySubsystem();
	fileSubsystem = new FileSubsystem();
	messagingSubsystem = new MessagingSubsystem();
	tokenBuffer = new TokenBuffer(memorySubsystem);
	spillFile = new SpillFile(memorySubsystem, fileSubsystem);
	symbolTable = new SymbolTable(memorySubsystem);
	orl = new Orl();
	virtualMemory = new VirtualMemory(memorySubsystem);
}

Linker::~Linker()
{
	DEBUG((DBG_OLD, "Linker destructor enter\n"));
	delete virtualMemory;
	delete orl;
	delete symbolTable;
	delete spillFile;
	delete tokenBuffer;
	delete messagingSubsystem;
	delete fileSubsystem;
	delete memorySubsystem;
	DEBUG((DBG_OLD, "Linker destructor exit\n"));
}

void Linker::DoLink()
{
	DEBUG((DBG_OLD, "DoLink enter\n"));
	DEBUG((DBG_OLD, "DoLink exit\n"));
}

int Linker::link()
{
	DEBUG((DBG_OLD, "Link enter\n"));
	DoLink();
	DEBUG((DBG_OLD, "Link exit\n"));
	return((LinkState & LINK_ERROR) ? 1 : 0);
}
