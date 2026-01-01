#pragma once

#include "MessagingSubsystem.h"
#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "Initialize.h"

class Linker
{
	MessagingSubsystem* msg;
	MemorySubsystem* memory;
	FileSubsystem* file;
public:
	Linker();
	~Linker();
	void mainLine();
	void InitSubSystems(void);
	void FiniSubSystems(void);
};

