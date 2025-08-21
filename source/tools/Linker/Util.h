#pragma once

int getBitCount(unsigned int a);
void ClearNbit(char * mask, long i);
void SetNbit(char * mask, long i);
char GetNbit(char * mask, long i);
long GetIndex(char * buf, long* index);
void ReportError(long errnum);
unsigned short wtoupper(unsigned short a);
int wstricmp(const char* s1, const char* s2);
int wstrlen(const char* s);
int sortCompare(const void* x1, const void* x2);
void* checkMalloc(size_t x);
void* checkRealloc(void* p, size_t x);
char* checkStrdup(const char* s);
SortEntryPtr binarySearch(SortEntryPtr list, unsigned int count, char* key);
void sortedInsert(SortEntryPtrPtr plist, unsigned int* pcount, char* key, void* object);
