#pragma once

#include "CmdPlatform.h"

class CmdNovell : public CmdPlatform
{
	char* Name;
	commandflag     CmdFlags;
public:
	CmdNovell();
	~CmdNovell();
	virtual void setFormat();
	virtual void freeFormat();
};

