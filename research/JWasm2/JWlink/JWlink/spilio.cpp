#include  "pch.h"
#include "spillio.h"
#include "ntio.h"

char* TFileName;
unsigned long TmpFSize;
f_handle TempFile;;

void InitSpillFile(void)
{
    TempFile = NIL_HANDLE;
    TFileName = NULL;
    TmpFSize = 0;
    SetBreak();
}
