#pragma once

#include "CmdPlatform.h"

class CmdPharlap : public CmdPlatform
{
public:
	CmdPharlap(MemorySubsystem* memory, MessagingSubsystem* msg);
	~CmdPharlap();
	virtual void setFormat();
	virtual void freeFormat();
};

