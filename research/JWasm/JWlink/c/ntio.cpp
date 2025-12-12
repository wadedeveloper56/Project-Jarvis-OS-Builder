#include "pch.h"
#include "globals.h"
#include "ntio.h"
#include "File.h"
#include "msg.h"
#include "wlnkmsg.h"

static int      OpenFiles;      // the number of open files
static unsigned LastResult;
static bool     CaughtBreak;    // set to TRUE if break hit.

#define TOOMANY EMFILE

void LnkFilesInit(void)
{
    OpenFiles = 0;
    CaughtBreak = false;
    setFileMode(_fileno(stdin), _O_BINARY);
    setFileMode(_fileno(stdout), _O_BINARY);
}

void TrapBreak(int sig_num)
{
    sig_num = sig_num;          // to avoid a warning, will be optimized out.
    CaughtBreak = TRUE;
}

void CheckBreak(void)
{
    if (CaughtBreak) {
        CaughtBreak = false;        /* prevent recursion */
        LnkMsg(FTL + MSG_BREAK_HIT, nullptr);    /* suicides */
    }
}

void SetBreak(void)
{
}

void RestoreBreak(void)
{
}

static FileHandle DoOpen(char* name, unsigned mode, bool isexe)
{
    FileHandle h;

    CheckBreak();
    mode |= O_BINARY;
    for (;; ) {
        h = OpenFile(name, mode, owner_read | owner_write);
        if (h != -1) {
            OpenFiles++;
            break;
        }
        if (errno != TOOMANY)
            break;
    }
    return(h);
}

FileHandle QOpenR(char* name)
{
    FileHandle h = DoOpen(name, O_RDONLY, FALSE);
    if (h != -1) return(h);
    LnkMsg(FTL + MSG_CANT_OPEN, "12", name, strerror(errno));
    return(NIL_HANDLE);
}

FileHandle QOpenRW(char* name)
{
    FileHandle h = DoOpen(name, O_RDWR | O_CREAT | O_TRUNC, FALSE);
    if (h != -1) return(h);
    LnkMsg(FTL + MSG_CANT_OPEN, "12", name, strerror(errno));
    return(NIL_HANDLE);
}

unsigned QRead(FileHandle file, void* buffer, unsigned len, char* name)
{
    CheckBreak();
    int h = ReadFile(file, buffer, len);
    if (h == -1) {
        LnkMsg(ERR + MSG_IO_PROBLEM, "12", name, strerror(errno));
    }
    return(h);
}

unsigned QWrite(FileHandle file, void* buffer, unsigned len, char* name)
{
    char    rc_buff[RESOURCE_MAX_SIZE];
    if (len == 0) return(0);
    CheckBreak();
    int h = WriteFile(file, buffer, len);
    if (name != nullptr) {
        if (h == -1) {
            LnkMsg(ERR + MSG_IO_PROBLEM, "12", name, strerror(errno));
        }
        else if (h != len) {
            Msg_Get(MSG_IOERRLIST_7, rc_buff);
            LnkMsg((FTL + MSG_IO_PROBLEM) & ~OUT_MAP, "12", name, rc_buff);
        }
    }
    return(h);
}

char NLSeq[] = { "\r\n" };

void QWriteNL(FileHandle file, char* name)
{
    QWrite(file, NLSeq, sizeof(NLSeq) - 1, name);
}

void QClose(FileHandle file, char* name)
{
    CheckBreak();
    int h = CloseFile(file);
    OpenFiles--;
    if (h != -1) return;
    LnkMsg(ERR + MSG_IO_PROBLEM, "12", name, strerror(errno));
}

__int64 QLSeek(FileHandle file, long position, int start, char* name)
{
    CheckBreak();
    __int64 h = FileSeek(file, position, start);
    if (h == -1 && name != nullptr) {
        LnkMsg(ERR + MSG_IO_PROBLEM, "12", name, strerror(errno));
    }
    return(h);
}

void QSeek(FileHandle file, long position, char* name)
{
    QLSeek(file, position, SEEK_SET, name);
}

__int64 QPos(FileHandle file)
{
    CheckBreak();
    return(FileSeek(file, 0LL, SEEK_CUR));
}

long QFileSize(FileHandle file)
{
    long result = _filelength(file);
    if (result == -1) {
        result = 0;
    }
    return result;
}

void QDelete(char* name)
{
    if (name == nullptr) return;
    int h = FileRemove(name);
    if (h == -1 && errno != ENOENT) { /* file not found is OK */
        LnkMsg(ERR + MSG_IO_PROBLEM, "12", name, strerror(errno));
    }
}

bool QReadStr(FileHandle file, char* dest, unsigned size, char* name)
{
    bool            eof;
    char            ch;

    eof = false;
    while (--size > 0) {
        if (QRead(file, &ch, 1, name) == 0) {
            eof = TRUE;
            break;
        }
        else if (ch != '\r') {
            *dest++ = ch;
        }
        if (ch == '\n') {
            break;
        }
    }
    *dest = '\0';
    return(eof);
}

bool QIsDevice(FileHandle file)
{
    return(_isatty(file));
}
