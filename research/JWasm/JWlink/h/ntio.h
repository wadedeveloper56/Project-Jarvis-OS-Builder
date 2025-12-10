#pragma once

#include "File.h"

#define MAX_OPEN_FILES 12       // the maximum number of open files.
#define RESOURCE_MAX_SIZE       128

void LnkFilesInit(void);
void CheckBreak(void);
void SetBreak(void);
void RestoreBreak(void);
FileHandle QOpenR(char* name);
FileHandle QOpenRW(char* name);
unsigned QRead(FileHandle file, void* buffer, unsigned len, char* name);
unsigned QWrite(FileHandle file, void* buffer, unsigned len, char* name);
void QWriteNL(FileHandle file, char* name);
void QClose(FileHandle file, char* name);
__int64 QLSeek(FileHandle file, long position, int start, char* name);
void QSeek(FileHandle file, long position, char* name);
__int64 QPos(FileHandle file);
long QFileSize(FileHandle file);
void QDelete(char* name);
bool QReadStr(FileHandle file, char* dest, unsigned size, char* name);
bool QIsDevice(FileHandle file);

