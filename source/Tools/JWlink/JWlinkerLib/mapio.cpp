#include "pch.h"
#include "mapio.h"
#include "Structs.h"
#include "globals.h"
#include "ring.h"
#include "MemorySubsystem.h"
#include "ntio.h"
#include "MessagingSubsystem.h"

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

void StartTime(void)
{
	StartT = time(NULL);
	ClockTicks = clock();
}

void EndTime(MessagingSubsystem* messageSubsystem)
{
	char* ptr;
	int16_t   h;
	int16_t   m;
	int16_t   s;
	int16_t   t;
	char tim[11 + 1];

	ClockTicks = clock() - ClockTicks;
	t = (uint16_t)(ClockTicks % CLOCKS_PER_SEC);
	ClockTicks /= CLOCKS_PER_SEC;
	s = (uint16_t)(ClockTicks % 60);
	ClockTicks /= 60;
	m = (uint16_t)(ClockTicks % 60);
	ClockTicks /= 60;
	h = (uint16_t)ClockTicks;
	sprintf(tim, "%02d:%02d:%02d.%02d", h, m, s, t);
	printf("Elapsed time %02d:%02d:%02d.%02d\n", h, m, s, t);
	if (MapFlags & MAP_FLAG)
	{
		messageSubsystem->Msg_Write_Map(MSG_MAP_LINK_TIME, tim);
	}
}

void FreeUndefs(MemorySubsystem* memorySubsystem)
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

unsigned MapPrint(MessagingSubsystem* messageSubsystem, char* str, va_list* args)
{
	char        buff[MAX_MSG_SIZE];
	unsigned    len;

	len = messageSubsystem->DoFmtStr(buff, MAX_MSG_SIZE, str, args);
	BufWrite(buff, len);
	return(len);
}

void DoWriteMap(MessagingSubsystem* messageSubsystem, char* format, va_list* arglist)
{
	if (MapFlags & MAP_FLAG)
	{
		MapPrint(messageSubsystem, format, arglist);
		WriteMapNL(1);
	}
}

void WriteMap(MessagingSubsystem* messageSubsystem, char* format, ...)
{
	va_list arglist;

	va_start(arglist, format);
	DoWriteMap(messageSubsystem, format, &arglist);
}
