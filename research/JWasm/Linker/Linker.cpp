#include "Linker.h"
#include "globals.h"
#include "structures.h"

Linker::Linker()
{
	LinkState = 0;
	memory = new MemorySubsystem();
	file = new FileSubsystem();
	messaging = new MessagingSubsystem(file);
	nodes = new Node(memory);
	tokenBuffer = new TokenBuffer(memory);
	spillFile = new SpillFile(file);
	symbolTable = new SymbolTable(memory);
	objorl = new ObjOrl(memory, file, tokenBuffer);
	cmdLine = new CmdLine();
	permData = new PermData(memory);
}

Linker::~Linker()
{
	delete permData;
	delete cmdLine;
	delete objorl;
	delete symbolTable;
	delete spillFile;
	delete tokenBuffer;
	delete nodes;
	delete messaging;
	delete file;
	delete memory;
}

void Linker::ResetSubSystems(void)
{
	permData->Reset();
}

void Linker::mainLine()
{
	ResetSubSystems();
}

void Linker::CleanSubSystems()
{
}
