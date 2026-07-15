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
#include "Structs.h"
#include "global.h"
#include "permdata.h"

Linker::Linker(int argc, char** argv)
{
	this->argc = argc;
	this->argv = argv;
	memorySubsystem = new MemorySubsystem();
	fileSubsystem = new FileSubsystem();
	messagingSubsystem = new MessagingSubsystem();
	tokenBuffer = new TokenBuffer(memorySubsystem);
	spillFile = new SpillFile(memorySubsystem);
	symbolTable = new SymbolTable(memorySubsystem);
	orl = new Orl();
	virtualMemory = new VirtualMemory(memorySubsystem);
	tempFileSubsystem = new TempFileSubsystem();

	InitNodes();
}

Linker::~Linker()
{
	DEBUG((DBG_OLD, "Linker destructor enter\n"));
	BurnNodes();
	delete tempFileSubsystem;
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

void* Linker::MakeArray(unsigned size)
{
	nodearray* nodes;

	_ChkAlloc(nodearray*, nodes, sizeof(nodearray));
	nodes->num = 0;
	nodes->elsize = size;
	nodes->arraymax = 0;
	size *= NODE_ARRAY_SIZE;
	_ChkAlloc(char*, nodes->array[0], size);
	memset(nodes->array[0], 0, size);
	return(nodes);
}

void Linker::InitNodes(void)
{
	GrpNodes = (nodearray*)MakeArray(sizeof(grpnode));
	SegNodes = (nodearray*)MakeArray(sizeof(segnode));
	ExtNodes = (nodearray*)MakeArray(sizeof(extnode));
	NameNodes = (nodearray*)MakeArray(sizeof(list_of_names*));
}

void Linker::BurnNodeArray(nodearray* list)
{
	int index;

	for (index = 0; index <= list->arraymax; index++)
	{
		_LnkFree(list->array[index]);
	}
	_LnkFree(list);
}

void Linker::BurnNodes(void)
{
	BurnNodeArray(GrpNodes);
	BurnNodeArray(SegNodes);
	BurnNodeArray(ExtNodes);
	BurnNodeArray(NameNodes);
}

void Linker::DoLink()
{
	DEBUG((DBG_OLD, "DoLink enter\n"));
	DEBUG((DBG_OLD, "DoLink exit\n"));
}

void Linker::ResetSubSystems()
{
	DEBUG((DBG_OLD, "ResetSubSystems enter\n"));
	ResetPermData(memorySubsystem);
	DEBUG((DBG_OLD, "ResetSubSystems exit\n"));
}

int Linker::link()
{
	DEBUG((DBG_OLD, "Link enter\n"));
	ResetSubSystems();
	DoLink();
	DEBUG((DBG_OLD, "Link exit\n"));
	return((LinkState & LINK_ERROR) ? 1 : 0);
}
