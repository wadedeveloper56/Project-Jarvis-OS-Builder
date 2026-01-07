#pragma once

#include "CmdPlatform.h"

class CmdPharlap : public CmdPlatform
{
public:
	CmdPharlap();
	~CmdPharlap();
	virtual void setFormat();
	virtual void freeFormat();
};

