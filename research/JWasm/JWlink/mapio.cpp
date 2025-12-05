#include "pch.h"
#include "globals.h"
#include "ntio.h"

typedef struct symrecinfo {
    struct symrecinfo* next;
    symbol* sym;
    mod_entry* mod;
} symrecinfo;

static symrecinfo* UndefList;
static symrecinfo* SymTraceList;
static  int             MapCol;
static  time_t          StartT;
static  clock_t         ClockTicks;
static  bool            Absolute_Seg;
static bool             Buffering;  // buffering on/off.
static int              BufferSize;          // # of chars in buffer.

void BufWrite(char* buffer, int len)
{
    int     diff;

    if (Buffering) {
        diff = BufferSize + len - TokSize;
        if (diff >= 0) {
            memcpy(TokBuff + BufferSize, buffer, len - diff);
            QWrite(MapFile, TokBuff, TokSize, MapFName);
            BufferSize = diff;
            if (diff > 0) {
                memcpy(TokBuff, buffer + len - diff, diff);
            }
        }
        else {
            memcpy(TokBuff + BufferSize, buffer, len);
            BufferSize += len;
        }
    }
    else {
        QWrite(MapFile, buffer, len, MapFName);
    }
}

extern char NLSeq[];

void WriteMapNL(unsigned count)
{
    unsigned    len;

    if (MapFlags & MAP_FLAG) {
        len = strlen(NLSeq);
        while (count != 0) {
            BufWrite(NLSeq, len);
            --count;
        }
        MapCol = 0;
    }
}

