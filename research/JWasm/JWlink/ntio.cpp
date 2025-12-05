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

FileHandle QOpenR(char* name)
{
    return(NIL_HANDLE);
}

FileHandle QOpenRW(char* name)
{
    return(NIL_HANDLE);
}

unsigned QWrite(FileHandle file, void* buffer, unsigned len, char* name)
{
    return 0;
}

void QWriteNL(FileHandle file, char* name)
{
}

unsigned QRead(FileHandle file, void* buffer, unsigned len, char* name)
{
    return 0;
}

bool QReadStr(FileHandle file, char* dest, unsigned size, char* name)
{
    return false;
}

void QClose(FileHandle file, char* name)
{
}

void QDelete(char* name)
{
}

unsigned long QFileSize(FileHandle file)
{
    return 0;
}

unsigned long QPos(FileHandle file)
{
    return 0;
}

time_t QFModTime(int handle)
{
    return 0;
}

bool QHavePath(char* name)
{
    return false;
}

long QLSeek(FileHandle file, long position, int start, char* name)
{
    return 0;
}

void QSeek(FileHandle file, long position, char* name)
{
}

bool QIsDevice(FileHandle file)
{
    return(_isatty(file));
}

