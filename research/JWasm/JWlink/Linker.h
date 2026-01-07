#pragma once

#include "Initialize.h"

class Linker
{
public:
	Linker();
	~Linker();
	void mainLine();
private:
	void InitSubSystems(void);
	void FiniSubSystems(void);
	void ResetSubSystems(void);
	void CleanSubSystems(void);
};

