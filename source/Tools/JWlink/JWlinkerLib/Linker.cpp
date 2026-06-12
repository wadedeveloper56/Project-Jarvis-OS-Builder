#include "pch.h"
#include "Linker.h"
#include "orl2.h"
#include "Memory.h"
#include "Orl2.h"

void InitNodes(shared_ptr<MemorySubsystem> memorySubsystem);
void BurnNodes(shared_ptr<MemorySubsystem> memorySubsystem);

Linker::Linker(int argc, char** argv)
{
	this->argc = argc;
	this->argv = argv;
	memorySubsystem = make_shared<MemorySubsystem>();
	fileSubsystem = make_shared<FileSubsystem>();
	messagingSubsystem = make_shared<MessagingSubsystem>();
	InitNodes(memorySubsystem);
	tokenBuffer = make_shared<TokenBuffer>(memorySubsystem);
	spillFile = make_shared<SpillFile>();
	symbolTable = make_shared<SymbolTable>(memorySubsystem);	
	orl = make_shared<Orl>();
}

Linker::~Linker()
{
	BurnNodes(memorySubsystem);
}

int Linker::link()
{
    return((LinkState & LINK_ERROR) ? 1 : 0);
}
