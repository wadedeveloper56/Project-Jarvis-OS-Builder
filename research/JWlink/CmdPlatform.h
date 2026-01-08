#pragma once

#include "globals.h"
#include "CmdUtils.h"

class CmdPlatform
{
protected:
	file_defext Extension;
	void ChkBase(offset align);
public:
	CmdPlatform();
	~CmdPlatform();
	virtual void setFormat() = 0;
	virtual void freeFormat() = 0;
};

