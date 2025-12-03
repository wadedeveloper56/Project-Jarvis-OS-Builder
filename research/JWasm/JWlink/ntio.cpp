#include "pch.h"
#include "ntio.h"
#include "File.h"

static int      OpenFiles;      // the number of open files
static unsigned LastResult;
static bool     CaughtBreak;

void LnkFilesInit(void)
{
    OpenFiles = 0;
    CaughtBreak = false;
    setFileMode(_fileno(stdin), _O_BINARY);
    setFileMode(_fileno(stdout), _O_BINARY);
}

void SetBreak(void)
{
}

void RestoreBreak(void)
{
}
