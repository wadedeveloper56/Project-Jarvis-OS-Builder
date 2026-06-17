#include "pch.h"
#include "libr.h"
#include "globals.h"

int ARCompName(const void* key, const void* vbase);
int ARCompIName(const void* key, const void* vbase);
int (*CmpARRtn)(const void*, const void*) = ARCompName;
int (*CmpOMFRtn)(const void*, const void*, size_t) = _memicmp;

void SetLibCase()
{
    if (LinkFlags & CASE_FLAG)
    {
        CmpOMFRtn = memcmp;
        CmpARRtn = ARCompName;
    }
    else
    {
        CmpOMFRtn = _memicmp;
        CmpARRtn = ARCompIName;
    }
}

int ARCompName(const void* key, const void* vbase)
{
    char** base;

    base = (char**)vbase;
    return strcmp((const char*)key, (const char*)*base);
}

int ARCompIName(const void* key, const void* vbase)
{
    char** base;

    base = (char**)vbase;
    return _stricmp((const char*)key, (const char*)*base);
}
