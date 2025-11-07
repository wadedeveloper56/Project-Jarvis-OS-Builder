#include "pch.h"
#include "linkstd.h"
#include "pcobj.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "fileio.h"
#include "strtab.h"
#include "carve.h"
#include "permdata.h"
#include "objio.h"

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
    _ChkAlloc(char *, TokBuff, MAX_HEADROOM);
}

void FreeTokBuffs(void)
{
    if (TokBuff != NULL) {
        _LnkFree(TokBuff);
        TokBuff = NULL;
    }
}

bool CleanCachedHandles(void)
{
    infilelist* list;

    for (list = CachedFiles; list != NULL; list = list->next) {
        if (!(list->flags & INSTAT_IN_USE) && list->handle != NIL_HANDLE)break;
    }
    if (list == NULL) return(FALSE);
    QClose(list->handle, list->name);
    list->handle = NIL_HANDLE;
    return(TRUE);
}
