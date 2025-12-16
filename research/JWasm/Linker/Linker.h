#pragma once

#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "Node.h"
#include "TokenBuffer.h"

class Linker
{
	MemorySubsystem* memory;
	FileSubsystem* file;
	MessagingSubsystem* messaging;
	Node* nodes;
	TokenBuffer* tokenBuffer;
public:
	Linker();
	~Linker();
	void mainLine();
};

