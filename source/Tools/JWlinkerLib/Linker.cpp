#include "pch.h"
#include "Linker.h"

Linker::Linker(int argc, char** argv)
{
	this->argc = argc;
	this->argv = argv;
}

Linker::~Linker()
{
}

int Linker::link()
{
    return 0;
}
