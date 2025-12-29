#pragma once

#include "CmdPlatform.h"

class CmdElf : public CmdPlatform
{
public:
	CmdElf(MemorySubsystem* memory, MessagingSubsystem* msg);
	~CmdElf();
	virtual void setFormat();
	virtual void freeFormat();
};

