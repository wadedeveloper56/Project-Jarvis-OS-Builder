#pragma once

#define NIL_HANDLE      ((f_handle)-1)
#define STDIN_HANDLE    ((f_handle)0)
#define STDOUT_HANDLE   ((f_handle)1)
#define STDERR_HANDLE   ((f_handle)2)
#define STDAUX_HANDLE   ((f_handle)3)
#define STDPRN_HANDLE   ((f_handle)4)

#define doread( f, b, l )  _read( f, b, l )
#define dowrite( f, b, l ) _write( f, b, l )

extern int      OpenFiles;      // the number of open files
extern unsigned LastResult;
extern bool     CaughtBreak;

void CheckBreak(void);
unsigned QRead(f_handle file, void* buffer, unsigned len, char* name);
long QLSeek(f_handle file, long position, int start, char* name);
void QSeek(f_handle file, long position, char* name);
void SetBreak(void);
void LnkFilesInit(void);
