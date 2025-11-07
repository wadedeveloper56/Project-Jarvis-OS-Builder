#include "pch.h"
#include "linkstd.h"
#include "pcobj.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "library.h"
#include "objnode.h"
#include "fileio.h"
#include "objio.h"
#include "objcache.h"
#include "ar.h"


static int ARCompName(const void* key, const void* vbase)
{
    char** base;

    base = (char**)vbase;
    return strcmp((char *)key, *base);
}

static int ARCompIName(const void* key, const void* vbase)
{
    char** base;

    base = (char**)vbase;
    return _stricmp((char *)key, *base);
}

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