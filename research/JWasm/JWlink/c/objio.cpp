#include "pch.h"
#include "globals.h"
#include "objio.h"
#include "mem.h"
#include "objstruct.h"

typedef struct {
    void* buffer;
    unsigned long       pos;
    infilelist* currfile;
} bufferedfile;

infilelist* CachedLibFiles;
infilelist* CachedFiles;

void ResetObjIO(void)
{
    CachedFiles = NULL;
    CachedLibFiles = NULL;
}

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
