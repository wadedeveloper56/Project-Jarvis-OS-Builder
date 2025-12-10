#include "pch.h"
#include "globals.h"
#include "spillio.h"
#include "ntio.h"

static char* TFileName;
static unsigned long    TmpFSize;

void InitSpillFile(void)
{
    TempFile = NIL_HANDLE;
    TFileName = NULL;
    TmpFSize = 0;
    SetBreak();
}
