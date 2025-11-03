#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "fileio.h"
#include "spillio.h"

static char* TFileName;
static unsigned long    TmpFSize;

void InitSpillFile(void)
{
    TempFile = NIL_HANDLE;
    TFileName = NULL;
    TmpFSize = 0;
    SetBreak();
}

