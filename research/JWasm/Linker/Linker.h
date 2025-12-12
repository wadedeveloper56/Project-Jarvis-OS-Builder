#pragma once

#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "NodeSubsystem.h"

class Linker
{
	MemorySubsystem* memory;
	FileSubsystem* file;
	MessagingSubsystem* messaging;
	NodeSubsystem* nodes;
public:
	Linker();
	~Linker();
	void mainLine();
};

