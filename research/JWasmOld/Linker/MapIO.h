#pragma once

#include "globals.h"
#include "ring.h"

typedef struct symrecinfo {
	struct symrecinfo* next;
	symbol* sym;
	mod_entry* mod;
} symrecinfo;

class MapIO
{
	Ring* ring;
	symrecinfo* UndefList;
	symrecinfo* SymTraceList;
public:
	MapIO(Ring* ring);
	~MapIO();
	void ResetMapIO(void);
	void FreeUndefs(void);
};

