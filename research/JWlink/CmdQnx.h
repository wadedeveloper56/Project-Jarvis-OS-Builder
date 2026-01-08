#pragma once

#include "CmdPlatform.h"

class CmdQnx : public CmdPlatform
{
public:
	CmdQnx();
	~CmdQnx();
	virtual void setFormat();
	virtual void freeFormat();
};

