#include "pch.h"
#include "mapio.h"
#include "Structs.h"
#include "globals.h"
#include "ring.h"
#include "MemorySubsystem.h"

using namespace std;

symrecinfo* UndefList;
symrecinfo* SymTraceList;
int             MapCol;
time_t          StartT;
clock_t         ClockTicks;
bool            Absolute_Seg;
bool             Buffering;
int              BufferSize;

void ResetMapIO()
{
	MapFlags = (mapflag)0;
	UndefList = NULL;
	SymTraceList = NULL;
}

void FreeUndefs(MemorySubsystem *memorySubsystem)
{
	RingFree(memorySubsystem, &SymTraceList);
	RingFree(memorySubsystem, &UndefList);
}

