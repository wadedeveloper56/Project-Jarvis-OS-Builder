#include "pch.h"
#include "objio.h"
#include "objnode.h"
#include "mem.h"

char* TokBuff;
unsigned TokSize;

void InitTokBuff(void)
{
    TokSize = MAX_HEADROOM;
    _ChkAlloc(char *, TokBuff, MAX_HEADROOM);
}
