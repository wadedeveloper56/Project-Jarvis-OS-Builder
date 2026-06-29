#include "pch.h"
#include "libr.h"
#include "globals.h"
#include "MemorySubsystem.h"
#include "Structs.h"
#include "objcache.h"

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

void FreeDictCache(shared_ptr<MemorySubsystem> memorySubsystem,void** cache, uint16_t buckets)
{
    while (buckets != 0)
    {
        memorySubsystem->FreeMemory(cache[--buckets]);
    }
    memorySubsystem->FreeMemory(cache);
}

void BurnLibs(shared_ptr<MemorySubsystem> memorySubsystem)
{
    file_list* temp;
    dict_entry* dict;

    for (temp = ObjLibFiles; temp != NULL; temp = (file_list*)temp->next_file)
    {
        if (temp->status & STAT_AR_LIB)
        {
            CacheFree(temp, temp->strtab);
            temp->strtab = NULL;
        }
        dict = temp->u.dict;
        if (dict == NULL) continue;
        if (temp->status & STAT_AR_LIB)
        {
            CacheFree(temp, dict->a.filepostab - 1);
            memorySubsystem->FreeMemory(dict->a.fnametab);
        }
        else
        {
            if (dict->o.cache != NULL)
            {
                FreeDictCache(memorySubsystem, dict->o.cache, (dict->o.pages / PAGES_IN_CACHE) + 1);
            }
        }
        memorySubsystem->FreeMemory(dict);
        temp->u.dict = NULL;
        FreeObjCache(temp);
    }
}

