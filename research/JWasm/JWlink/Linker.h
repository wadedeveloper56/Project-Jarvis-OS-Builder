#pragma once

#include "MessagingSubsystem.h"
#include "MemorySubsystem.h"
#include "FileSubsystem.h"

class Linker
{
	MessagingSubsystem* msg;
	MemorySubsystem* memory;
	FileSubsystem* file;
public:
	Linker();
	~Linker();
	void mainLine();
};

