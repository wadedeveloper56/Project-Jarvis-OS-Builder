#include "pch.h"
#include "MapIO.h"

MapIO::MapIO(Ring* ring)
{
	this->ring = ring;
	ResetMapIO();
}

MapIO::~MapIO()
{
}	

void MapIO::ResetMapIO(void)
{
    MapFlags = (mapflag)0;
    UndefList = nullptr;
    SymTraceList = nullptr;
}

void MapIO::FreeUndefs(void)
{
    ring->RingFree(&SymTraceList);
    ring->RingFree(&UndefList);
}
