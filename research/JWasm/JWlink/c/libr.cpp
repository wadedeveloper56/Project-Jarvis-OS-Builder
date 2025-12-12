#include "pch.h"
#include "globals.h"
#include "libr.h"
#include "mem.h"
#include "mixcache.h"

typedef struct omf_dict_entry {
    void** cache;          /* for extra memory store of dictionary */
    unsigned_32 start;          /* recno of start of dictionary         */
    unsigned_16 pages;          /* number of pages in dictionary        */
    unsigned_16 rec_length;     /* record alignment of obj recs         */
    byte* buffer;
} omf_dict_entry;

typedef struct ar_dict_entry {
    unsigned_32* filepostab;
    unsigned_16* offsettab;
    char** fnametab;
    unsigned_32         num_entries;
} ar_dict_entry;

typedef union dict_entry {
    omf_dict_entry      o;
    ar_dict_entry       a;
} dict_entry;

#define PAGES_IN_CACHE      0x40U

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
    char** base;

    base = (char**)vbase;
    return strcmp((const char *)key, *base);
}

static int ARCompIName(const void* key, const void* vbase)
{
    char** base;

    base = (char**)vbase;
    return _stricmp((const char*)key, *base);
}

static void FreeDictCache(void** cache, unsigned_16 buckets)
{
    while (buckets != 0) {
        _LnkFree(cache[--buckets]);
    }
    _LnkFree(cache);
}

void BurnLibs(void)
{
    file_list* temp;
    dict_entry* dict;

    for (temp = ObjLibFiles; temp != nullptr; temp = temp->next_file) {
        if (temp->status & STAT_AR_LIB) {
            CacheFree(temp, temp->strtab);
            temp->strtab = nullptr;
        }
        dict = temp->u.dict;
        if (dict == nullptr) continue;
        if (temp->status & STAT_AR_LIB) {
            CacheFree(temp, dict->a.filepostab - 1);
            _LnkFree(dict->a.fnametab);
        }
        else {
            if (dict->o.cache != nullptr) {
                FreeDictCache(dict->o.cache, (dict->o.pages / PAGES_IN_CACHE) + 1);
            }
        }
        _LnkFree(dict);
        temp->u.dict = nullptr;
        FreeObjCache(temp);
    }
}

