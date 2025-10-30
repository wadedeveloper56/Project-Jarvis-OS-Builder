#include "pch.h"
#include "ntio.h"

int      OpenFiles;      // the number of open files
unsigned LastResult;
bool     CaughtBreak;

void LnkFilesInit(void)
{
    OpenFiles = 0;
    CaughtBreak = false;
    _setmode(STDIN_HANDLE, O_BINARY);
    _setmode(STDOUT_HANDLE, O_BINARY);
}