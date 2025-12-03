#include "pch.h"
#include "objio.h"
#include "globals.h"
#include "alloc.h"

void InitTokBuff(void)
{
    TokSize = MAX_HEADROOM;
    _ChkAlloc(char*, TokBuff, MAX_HEADROOM);
}

void FreeTokBuffs(void)
{
    if (TokBuff != NULL) {
        _LnkFree(TokBuff);
        TokBuff = NULL;
    }
}