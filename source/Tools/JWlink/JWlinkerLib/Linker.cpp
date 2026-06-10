#include "pch.h"
#include "Linker.h"
#include "orl.h"
#include "Memory.h"

void InitNodes(shared_ptr<MemorySubsystem> memorySubsystem);
void BurnNodes(shared_ptr<MemorySubsystem> memorySubsystem);

orl_funcs ORLFuncs = { nullptr, nullptr, AllocateMemory, FreeMemory };

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
	ORLHandle = ORLInit(&ORLFuncs);
}

Linker::~Linker()
{
	BurnNodes(memorySubsystem);
	ORLFini(ORLHandle);
}

int Linker::link()
{
    return((LinkState & LINK_ERROR) ? 1 : 0);
}
