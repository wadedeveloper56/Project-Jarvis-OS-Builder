#pragma once

#include "globals.h"

typedef struct symrecinfo {
	struct symrecinfo* next;
	symbol* sym;
	mod_entry* mod;
} symrecinfo;

class MapIO
{
	symrecinfo* UndefList;
	symrecinfo* SymTraceList;
public:
	MapIO();
	~MapIO();
	void ResetMapIO(void);
};

