#pragma once

#include "MemorySubsystem.h"

class Linker
{
	MemorySubsystem* memory;
public:
	Linker();
	~Linker();
	void mainLine();
};

