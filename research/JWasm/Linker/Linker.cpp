#include "Linker.h"
#include "globals.h"

Linker::Linker()
{
	LinkState = 0;
	memory = new MemorySubsystem();
}

Linker::~Linker()
{
	delete memory;
}

void Linker::mainLine()
{
}
