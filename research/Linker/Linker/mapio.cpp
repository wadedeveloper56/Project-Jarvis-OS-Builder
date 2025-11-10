#include "pch.h"
#include "linkstd.h"
#include "pcobj.h"
#include "newmem.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "objnode.h"
#include "loadfile.h"
#include "fileio.h"
#include "overlays.h"
#include "ring.h"
#include "mapio.h"

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
    MapFlags = (enum mapflag)0;
    UndefList = NULL;
    SymTraceList = NULL;
}

void DoWriteMap(char* format, va_list* arglist)
{
    //FIX ME
}

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
