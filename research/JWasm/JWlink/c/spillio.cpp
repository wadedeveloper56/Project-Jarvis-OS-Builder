#include "pch.h"
#include "globals.h"
#include "spillio.h"
#include "ntio.h"
#include "mem.h"

static char* TFileName;
static unsigned long    TmpFSize;

void InitSpillFile(void)
{
    TempFile = NIL_HANDLE;
    TFileName = NULL;
    TmpFSize = 0;
    SetBreak();
}

void CloseSpillFile(void)
{
    if (TempFile != NIL_HANDLE) {
        RestoreBreak();
        QClose(TempFile, TFileName);
        QDelete(TFileName);
        _LnkFree(TFileName);
        TFileName = NULL;
        TempFile = NIL_HANDLE;
    }
}
