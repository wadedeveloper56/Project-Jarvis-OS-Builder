#include "PermData.h"

PermData::PermData(MemorySubsystem* memory, /*Ring* ring,*/ Carve* carve)
{
	this->memory = memory;
	//this->ring = ring;
	this->carve = carve;
}

PermData::~PermData()
{
}

void PermData::Reset(void)
{
}
