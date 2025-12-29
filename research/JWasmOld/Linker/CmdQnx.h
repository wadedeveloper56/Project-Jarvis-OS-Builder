#pragma once

#include "CmdPlatform.h"

class CmdQnx : public CmdPlatform
{
public:
	CmdQnx(MemorySubsystem* memory, MessagingSubsystem* msg);
	~CmdQnx();
	virtual void setFormat();
	virtual void freeFormat();
};

