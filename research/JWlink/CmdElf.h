#pragma once

#include "CmdPlatform.h"

class CmdElf : public CmdPlatform
{
public:
	CmdElf();
	~CmdElf();
	virtual void setFormat();
	virtual void freeFormat();
};

