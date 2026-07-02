#include "pch.h"
#include "mapio.h"
#include "Structs.h"
#include "globals.h"
#include "ring.h"
#include "MemorySubsystem.h"
#include "ntio.h"

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

void BufWrite(char* buffer, int len)
{
    int     diff;

    if (Buffering)
    {
        diff = BufferSize + len - TokSize;
        if (diff >= 0)
        {
            memcpy(TokBuff + BufferSize, buffer, len - diff);
            QWrite(MapFile, TokBuff, TokSize, MapFName);
            BufferSize = diff;
            if (diff > 0)
            {
                memcpy(TokBuff, buffer + len - diff, diff);
            }
        }
        else
        {
            memcpy(TokBuff + BufferSize, buffer, len);
            BufferSize += len;
        }
    }
    else
    {
        QWrite(MapFile, buffer, len, MapFName);
    }
}

void WriteMapNL(unsigned count)
{
    unsigned    len;

    if (MapFlags & MAP_FLAG)
    {
        len = strlen(NLSeq);
        while (count != 0)
        {
            BufWrite(NLSeq, len);
            --count;
        }
        MapCol = 0;
    }
}