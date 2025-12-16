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
}

Linker::~Linker()
{
	delete tokenBuffer;
	delete nodes;
	delete messaging;
	delete file;
	delete memory;
}

void Linker::mainLine()
{
}
