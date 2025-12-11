#include "pch.h"
#include "globals.h"
#include "mapio.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "ntio.h"
#include "ring.h"

#undef pick
#define pick( num, string ) string

static char* MsgStrings[] = {
#include "msg.h"

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

void ResetMapIO(void)
{
    MapFlags = (mapflag)0;
    UndefList = NULL;
    SymTraceList = NULL;
}

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

char NLSeq2[] = { "\r\n" };

void WriteMapNL(unsigned count)
{
    unsigned    len;

    if (MapFlags & MAP_FLAG) {
        len = strlen(NLSeq2);
        while (count != 0) {
            BufWrite(NLSeq2, len);
            --count;
        }
        MapCol = 0;
    }
}

void FreeUndefs(void)
{
    RingFree(&SymTraceList);
    RingFree(&UndefList);
}
