#pragma once

#include "MessagingSubsystem.h"
#include "MemorySubsystem.h"

class CmdPlatform
{
protected:
	file_defext Extension;
	MessagingSubsystem* msg;
	MemorySubsystem* memory;
	void ChkBase(MessagingSubsystem* msg, offset align);
public:
	CmdPlatform(MemorySubsystem* memory, MessagingSubsystem* msg);
	~CmdPlatform();
	virtual void setFormat() = 0;
	virtual void freeFormat() = 0;
};

