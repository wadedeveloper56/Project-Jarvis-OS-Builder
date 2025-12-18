#include "pch.h"
#include "libr.h"
#include "globals.h"

static int ARCompName(const void* key, const void* vbase);
static int ARCompIName(const void* key, const void* vbase);
int (*CmpARRtn)(const void*, const void*) = ARCompName;
int (*CmpOMFRtn)(const void*, const void*, size_t) = memcmp;

void SetLibCase(void)
{
    if (LinkFlags & CASE_FLAG) {
        CmpOMFRtn = memcmp;
        CmpARRtn = ARCompName;
    }
    else {
        CmpOMFRtn = _memicmp;
        CmpARRtn = ARCompIName;
    }
}

static int ARCompName(const void* key, const void* vbase)
{
    char** base = (char**)vbase;
    return strcmp((const char *)key, *base);
}

static int ARCompIName(const void* key, const void* vbase)
{
    char** base = (char**)vbase;
    return _stricmp((const char*)key, *base);
}
