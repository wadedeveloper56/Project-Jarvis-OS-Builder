#include "pch.h"
#include "Linker.h"

Linker::Linker()
{
	file = new FileSubsystem();
	msg = new MessagingSubsystem(file);
	memory = new MemorySubsystem(msg);
}

Linker::~Linker()
{
	delete memory;
	delete msg;
	delete file;
}

void Linker::mainLine()
{
}
