#include "Linker.h"
#include "globals.h"
#include "structures.h"

Linker::Linker()
{
	LinkState = 0;
	memory = new MemorySubsystem();
	file = new FileSubsystem();
	messaging = new MessagingSubsystem(file);
	nodes = new NodeSubsystem(memory);
}

Linker::~Linker()
{
	delete nodes;
	delete messaging;
	delete file;
	delete memory;
}

void Linker::mainLine()
{
}
