#pragma once

#define STDIN_HANDLE    ((f_handle)0)
#define STDOUT_HANDLE   ((f_handle)1)
#define STDERR_HANDLE   ((f_handle)2)
#define STDAUX_HANDLE   ((f_handle)3)
#define STDPRN_HANDLE   ((f_handle)4)

extern int      OpenFiles;      // the number of open files
extern unsigned LastResult;
extern bool     CaughtBreak;

void LnkFilesInit(void);
