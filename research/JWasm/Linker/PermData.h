#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "Ring.h"
#include "Carve.h"

class PermData
{
    MemorySubsystem* memory;
    Ring* ring;
	Carve* carve;
public:
	PermData(MemorySubsystem* memory, Ring* ring, Carve* carve);
	~PermData();
	void Reset(void);
};
