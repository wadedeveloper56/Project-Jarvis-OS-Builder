#include "pch.h"
#include "Linker.h"

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
}

Linker::~Linker()
{
	BurnNodes(memorySubsystem);
}

int Linker::link()
{
    return((LinkState & LINK_ERROR) ? 1 : 0);
}
