#include "pch.h"
#include <fcntl.h>
#include "ntio.h"
#include "Structs.h"
#include "globals.h"
#include "File.h"
#include "MessagingSubsystem.h"
#include "objio.h"
#include "FileSubsystem.h"

int      OpenFiles;           
unsigned LastResult;

time_t QFModTime(int handle)
{
    struct stat buf;

    fstat(handle, &buf);
    return buf.st_mtime;
}

int DoOpen(FileSubsystem *fileSubsystem, char* name, unsigned mode, bool isexe)
{
    int     h;

    mode |= O_BINARY;
    for (;; )
    {
        if (OpenFiles >= MAX_OPEN_FILES) CleanCachedHandles();
        h = fileSubsystem->OpenFile(name, mode, S_IRUSR | S_IWUSR);
        if (h != -1)
        {
            OpenFiles++;
            break;
        }
        if (errno != TOOMANY)
            break;
        if (!CleanCachedHandles())
        {
            break;
        }
    }
    return(h);
}

f_handle NSOpen(FileSubsystem* fileSubsystem, char* name, unsigned mode)
{
    int h = DoOpen(fileSubsystem, name, mode, FALSE);
    LastResult = h;
    if (h != -1)
        return(h);
    return(NIL_HANDLE);
}

f_handle ExeOpen(FileSubsystem* fileSubsystem, char* name)
{
    return(NSOpen(fileSubsystem, name, TIO_READ_WRITE));
}

f_handle QObjOpen(FileSubsystem* fileSubsystem, char* name)
{
    return(NSOpen(fileSubsystem, name, TIO_READ));
}

f_handle TempFileOpen(FileSubsystem* fileSubsystem, char* name)
{
    return(NSOpen(fileSubsystem, name, TIO_READ));
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

char NLSeq[] = { "\r\n" };

void QWriteNL(f_handle file, char* name)
{
    QWrite(file, NLSeq, sizeof(NLSeq) - 1, name);
}

void QClose(f_handle file, char* name)
{
	CloseFile2(file);
}

void QDelete(char* name)
{
	remove(name);
}

f_handle QOpenR(FileSubsystem* fileSubsystem, char* name)
{
    int     h;

    h = DoOpen(fileSubsystem, name, O_RDONLY, FALSE);
    if (h != -1)
        return(h);
    return(NIL_HANDLE);
}

f_handle QOpenRW(FileSubsystem* fileSubsystem, char* name)
{
    int     h;

    h = DoOpen(fileSubsystem, name, O_RDWR | O_CREAT | O_TRUNC, FALSE);
    if (h != -1)
        return(h);
    return(NIL_HANDLE);
}

void QSeek(f_handle file, long position, char* name)
{
    QLSeek(file, position, SEEK_SET, name);
}
