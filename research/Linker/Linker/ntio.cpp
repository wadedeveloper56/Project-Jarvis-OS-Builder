#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "objio.h"
#include "fileio.h"
#include "ntio.h"

#define TOOMANY EMFILE
#define doread( f, b, l )  _read( f, b, l )
#define dowrite( f, b, l ) _write( f, b, l )

static int      OpenFiles;      // the number of open files
static unsigned LastResult;
static bool     CaughtBreak;    // set to TRUE if break hit.

void LnkFilesInit(void)
{
    OpenFiles = 0;
    CaughtBreak = FALSE;
    setmode(STDIN_HANDLE, O_BINARY);
    setmode(STDOUT_HANDLE, O_BINARY);
}

void CheckBreak(void)
{
#ifdef __OSI__
    if (*_BreakFlagPtr) {
        *_BreakFlagPtr = 0;
        LnkMsg(FTL + MSG_BREAK_HIT, NULL);    /* suicides */
    }
#else
    if (CaughtBreak) {
        CaughtBreak = FALSE;        /* prevent recursion */
        LnkMsg(FTL + MSG_BREAK_HIT, NULL);    /* suicides */
    }
#endif
}

void SetBreak(void)
{
}

static int DoOpen(char* name, unsigned mode, bool isexe)
{
    int     h;

    isexe = isexe;
    CheckBreak();
    mode |= O_BINARY;
    for (;; ) {
        if (OpenFiles >= MAX_OPEN_FILES)
            CleanCachedHandles();
        h = _open(name, mode, _S_IREAD | _S_IWRITE);
        if (h != -1) {
            OpenFiles++;
            break;
        }
        if (errno != TOOMANY)
            break;
        if (!CleanCachedHandles()) {
            break;
        }
    }
    return(h);
}

static f_handle NSOpen(char* name, unsigned mode)
{
    int         h;

    h = DoOpen(name, mode, FALSE);
    LastResult = h;
    if (h != -1)
        return(h);
    return(NIL_HANDLE);
}

f_handle QObjOpen(char* name)
{
    return(NSOpen(name, O_RDONLY));
}

f_handle TempFileOpen(char* name)
{
    return(NSOpen(name, O_RDWR));
}

void QClose(f_handle file, char* name)
{
    int         h;

    CheckBreak();
    h = _close(file);
    OpenFiles--;
    if (h != -1)
        return;
    LnkMsg(ERR + MSG_IO_PROBLEM, "12", name, strerror(errno));
}

unsigned QWrite(f_handle file, void* buffer, unsigned len, char* name)
{
    int     h;
    char    rc_buff[RESOURCE_MAX_SIZE];

    if (len == 0)
        return(0);

#ifdef _INT_DEBUG
    {
        unsigned long pos = QPos(file);
        if (pos <= SpyWrite && SpyWrite <= pos + len
            && file == Root->outfile->handle) {
            DEBUG((DBG_ALWAYS, "About to write to %s (handle %d) %d bytes at position %d:",
                name, file, len, pos));
            PrintMemDump(buffer, len, DUMP_BYTE);
        }
    }
#endif

    CheckBreak();
    h = dowrite(file, buffer, len);
    if (name != NULL) {
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

void QDelete(char* name)
{
    int   h;

    if (name == NULL)
        return;
    h = remove(name);
    if (h == -1 && errno != ENOENT) { /* file not found is OK */
        LnkMsg(ERR + MSG_IO_PROBLEM, "12", name, strerror(errno));
    }
}

long QLSeek(f_handle file, long position, int start, char* name)
{
    long int    h;

    CheckBreak();
    h = _lseek(file, position, start);
    if (h == -1 && name != NULL) {
        LnkMsg(ERR + MSG_IO_PROBLEM, "12", name, strerror(errno));
    }
    return(h);
}

void QSeek(f_handle file, long position, char* name)
{
    QLSeek(file, position, SEEK_SET, name);
}

char NLSeq[] = { "\r\n" }; 
void QWriteNL(f_handle file, char* name)
{
    QWrite(file, NLSeq, sizeof(NLSeq) - 1, name);
}
