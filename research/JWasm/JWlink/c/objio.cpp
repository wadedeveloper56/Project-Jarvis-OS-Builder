#include "pch.h"
#include "globals.h"
#include "objio.h"
#include "mem.h"

void InitTokBuff(void)
{
    TokSize = MAX_HEADROOM;
    _ChkAlloc(char *,TokBuff, MAX_HEADROOM);
}

void FreeTokBuffs(void)
{
    if (TokBuff != NULL) {
        _LnkFree(TokBuff);
        TokBuff = NULL;
    }
}
