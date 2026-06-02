#include "pch.h"
#include "Linker.h"

Linker::Linker(int argc, char** argv)
{
	this->argc = argc;
	this->argv = argv;
	memorySubsystem = make_shared<MemorySubsystem>();
}

Linker::~Linker()
{
}

int Linker::link()
{
    return((LinkState & LINK_ERROR) ? 1 : 0);;
}
