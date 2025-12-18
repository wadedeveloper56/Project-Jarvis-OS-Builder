#include "pch.h"
#include "MapIO.h"

MapIO::MapIO()
{
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
