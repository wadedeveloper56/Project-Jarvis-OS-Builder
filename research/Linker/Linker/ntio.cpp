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

void LnkFilesInit(void)
{
    OpenFiles = 0;
    CaughtBreak = FALSE;
    setmode(STDIN_HANDLE, O_BINARY);
    setmode(STDOUT_HANDLE, O_BINARY);
}

void SetBreak(void)
{
}

static int DoOpen(char* name, unsigned mode, bool isexe)
{
    int     h;

    isexe = isexe;
    //CheckBreak();
    mode |= O_BINARY;
    for (;; ) {
        //if (OpenFiles >= MAX_OPEN_FILES)
        //    CleanCachedHandles();
        h = _open(name, mode, _S_IREAD | _S_IWRITE);
        if (h != -1) {
            OpenFiles++;
            break;
        }
        //if (errno != TOOMANY)
        //    break;
        //if (!CleanCachedHandles()) {
        //    break;
        //}
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
