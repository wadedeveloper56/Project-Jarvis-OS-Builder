#pragma once

#include "CmdPlatform.h"

class CmdNovell : public CmdPlatform
{
	char* Name;
	commandflag     CmdFlags;
public:
	CmdNovell(MemorySubsystem* memory, MessagingSubsystem* msg);
	~CmdNovell();
	virtual void setFormat();
	virtual void freeFormat();
};

