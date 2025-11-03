#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "objio.h"
#include "fileio.h"
#include "ntio.h"

static int      OpenFiles;      // the number of open files
static unsigned LastResult;
static bool     CaughtBreak;    // set to TRUE if break hit.

void SetBreak(void)
{
}

void RestoreBreak(void)
{
}

void LnkFilesInit(void)
{
    OpenFiles = 0;
    CaughtBreak = FALSE;
#if !defined( _DLLHOST )
    _setmode(STDIN_HANDLE, O_BINARY);
    _setmode(STDOUT_HANDLE, O_BINARY);
#endif
}