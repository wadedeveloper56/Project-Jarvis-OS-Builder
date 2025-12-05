#pragma once

#include "File.h"

void LnkFilesInit(void);
void SetBreak(void);
void RestoreBreak(void);
FileHandle QOpenR(char* name);
FileHandle QOpenRW(char* name);
unsigned QWrite(FileHandle file, void* buffer, unsigned len, char* name);
void QWriteNL(FileHandle file, char* name);
unsigned QRead(FileHandle file, void* buffer, unsigned len, char* name);
bool QReadStr(FileHandle file, char* dest, unsigned size, char* name);
void QClose(FileHandle file, char* name);
void QDelete(char* name);
unsigned long QFileSize(FileHandle file);
unsigned long QPos(FileHandle file);
time_t QFModTime(int handle);
bool QHavePath(char* name);
long QLSeek(FileHandle file, long position, int start, char* name);
void QSeek(FileHandle file, long position, char* name);
bool QIsDevice(FileHandle file);
