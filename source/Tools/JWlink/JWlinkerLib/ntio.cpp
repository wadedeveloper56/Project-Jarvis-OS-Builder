#include "pch.h"
#include <fcntl.h>
#include <io.h>
#include <conio.h>
#include "ntio.h"
#include "Structs.h"
#include "globals.h"
#include "File.h"
#include "MessagingSubsystem.h"
#include "objio.h"
#include "FileSubsystem.h"

int      OpenFiles;           
unsigned LastResult;
bool     CaughtBreak;          

void TrapBreak(int sig_num)
{       
    CaughtBreak = TRUE;
}

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

int _bgetcmd(char ***_argv, char* buffer, int len)
{
    int     total;
    int     i;
    char* word;
    char* p = NULL;
    char** argv = *_argv;

    --len;      

    if (buffer && (len > 0))
    {
        p = buffer;
        *p = '\0';
    }

    for (word = *argv++, i = 0, total = 0; word; word = *argv++)
    {
        i = strlen(word);
        total += i;

        if (p)
        {
            if (i >= len)
            {
                strncpy(p, word, len);
                p[len] = '\0';
                p = NULL;
                len = 0;
            }
            else
            {
                strcpy(p, word);
                p += i;
                len -= i;
            }
        }

        if (*argv)
        {
            if (p)
            {
                *p++ = ' ';
                --len;
            }
            ++total;
        }
    }

    return(total);
}

char* getcmd(char ***_argv, char* buffer)
{
    _bgetcmd(_argv, buffer, 1024);
    return(buffer);
}

void GetCmdLine(char*** _argv, char* buff)
{
    getcmd(_argv, buff);
}

bool QIsDevice(f_handle file)
{
    return(_isatty(file));
}

bool QSysHelp(char** cmd_ptr)
{
    return(FALSE);
}

char WaitForKey()
{
    return _getch();
}

bool QReadStr(f_handle file, char* dest, unsigned size, char* name)
{
    bool            eof;
    char            ch;

    eof = FALSE;
    while (--size > 0)
    {
        if (QRead(file, &ch, 1, name) == 0)
        {
            eof = TRUE;
            break;
        }
        else if (ch != '\r')
        {
            *dest++ = ch;
        }
        if (ch == '\n')
        {
            break;
        }
    }
    *dest = '\0';
    return(eof);
}
