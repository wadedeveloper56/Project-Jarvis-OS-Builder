#include "pch.h"
#include <fcntl.h>
#include "ntio.h"
#include "Structs.h"
#include "globals.h"
#include "File.h"
#include "MessagingSubsystem.h"

void MessagingSubsystem::Locator(char* filename, char* mem, unsigned rec)
{
    LocFile = filename;
    LocMem = mem;
    LocRec = rec;
}

time_t QFModTime(int handle)
{
    struct stat buf;

    fstat(handle, &buf);
    return buf.st_mtime;
}

f_handle NSOpen(char* name, unsigned mode)
{
    f_handle fh = NIL_HANDLE;
    int oflag=0;
    int shflag=0;
    int pmode=0;
    if (mode == TIO_READ_WRITE)
    {
        oflag = _O_RDWR;
		shflag = _SH_DENYNO;
		pmode = S_IREAD | S_IWRITE;
    }
    OpenFile2(&fh, name, oflag, shflag, pmode);
    return(fh);
}

f_handle ExeOpen(char* name)
{
    return(NSOpen(name, TIO_READ_WRITE));
}

f_handle QObjOpen(char* name)
{
    return(NSOpen(name, TIO_READ));
}

f_handle TempFileOpen(char* name)
{
    return(NSOpen(name, TIO_READ));
}

int QMakeFileName(char** pos, char* name, char* fname)
{
    char* pathptr;
    unsigned int        path_len;
    char* file_ptr;

    pathptr = *pos;
    if (pathptr == NULL) return(0);
    while (*pathptr != '\0')
    {
        if (*pathptr == PATH_LIST_SEP) *pos = ++pathptr;
        for (;;)
        {
            if (*pathptr == '\0') break;
            if (*pathptr == PATH_LIST_SEP) break;
            pathptr++;
        }
        path_len = pathptr - *pos;
        if (path_len != 0)
        {
            memcpy(fname, *pos, path_len);
            file_ptr = fname + path_len;
            switch (file_ptr[-1])
            {
            CASE_PATH_SEP:
                break;
                default:
                    *file_ptr++ = PATH_SEP;
                    break;
            }
            strcpy(file_ptr, name);
            *pos = pathptr;
            return(1);
        }
        *pos = pathptr;
    }
    return(0);
}

bool QHavePath(char* name)
{
    return(*name == '\\' || *name == '/' || *(name + 1) == ':');
}

unsigned long QFileSize(f_handle file)
{
	return FileSize2(file);
}

long QLSeek(f_handle file, long position, int start, char* name)
{
	return FileSeek2(file, position, start);
}

unsigned QRead(f_handle file, void* buffer, unsigned len, char* name)
{
	return ReadFile2(file, buffer, len);
}

unsigned QWrite(f_handle file, void* buffer, unsigned len, char* name)
{
	return WriteFile2(file, buffer, len);
}

void QClose(f_handle file, char* name)
{
	CloseFile2(file);
}

void QDelete(char* name)
{
	remove(name);
}

//FIXME
f_handle QOpenR(char* name)
{
    int     h;

    h = 0;// DoOpen(name, O_RDONLY, FALSE);
    if (h != -1)
        return(h);
    //LnkMsg(FTL + MSG_CANT_OPEN, "12", name, strerror(errno));
    return(NIL_HANDLE);
}

//FIXME
f_handle QOpenRW(char* name)
{
    int     h;

    h = 0;// DoOpen(name, O_RDWR | O_CREAT | O_TRUNC, FALSE);
    if (h != -1)
        return(h);
    //LnkMsg(FTL + MSG_CANT_OPEN, "12", name, strerror(errno));
    return(NIL_HANDLE);
}

void QSeek(f_handle file, long position, char* name)
{
    //QLSeek(file, position, SEEK_SET, name);
}
