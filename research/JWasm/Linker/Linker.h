#pragma once

#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"

class Linker
{
	MemorySubsystem* memory;
	FileSubsystem* file;
	MessagingSubsystem* messaging;
public:
	Linker();
	~Linker();
	void mainLine();
};

