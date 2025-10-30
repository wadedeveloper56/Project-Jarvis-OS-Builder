#include "pch.h"
#include "ntio.h"
#include "msg.h"
#include "wlnkmsg.h"

int      OpenFiles;      // the number of open files
unsigned LastResult;
bool     CaughtBreak;

void CheckBreak(void)
{
    if (CaughtBreak) {
        CaughtBreak = false;        /* prevent recursion */
        LnkMsg(FTL + MSG_BREAK_HIT, NULL);    /* suicides */
    }
}

unsigned QRead(f_handle file, void* buffer, unsigned len, char* name)
{
    int     h;

    CheckBreak();
    h = doread(file, buffer, len);
    if (h == -1) {
        LnkMsg(ERR + MSG_IO_PROBLEM, (char *)"12", name, strerror(errno));
    }
    return(h);
}

long QLSeek(f_handle file, long position, int start, char* name)
{
    long int    h;

    CheckBreak();
    h = _lseek(file, position, start);
    if (h == -1 && name != NULL) {
        LnkMsg(ERR + MSG_IO_PROBLEM, (char *)"12", name, strerror(errno));
    }
    return(h);
}

void QSeek(f_handle file, long position, char* name)
{
    QLSeek(file, position, SEEK_SET, name);
}

void SetBreak(void)
{
}

void LnkFilesInit(void)
{
    OpenFiles = 0;
    CaughtBreak = false;
    _setmode(STDIN_HANDLE, O_BINARY);
    _setmode(STDOUT_HANDLE, O_BINARY);
}