#include "pch.h"
#include "objorl.h"
#include "types.h"
#include "Memory.h"
#include "orl.h"
#include "objstruct.h"

static long ORLSeek(void* _list, long pos, int where);
static void* ORLRead(void* _list, size_t len);

static orl_handle       ORLHandle;
static long             ORLFilePos;
static orl_funcs        ORLFuncs = { ORLRead, ORLSeek, AllocateMemory, FreeMemory };
static orl_reloc        SavedReloc;
static char* ImpExternalName;
static char* ImpModName;
static char* FirstCodeSymName;
static char* FirstDataSymName;
static unsigned_32      ImpOrdinal;

typedef struct readcache READCACHE;

typedef struct readcache {
    READCACHE* next;
    void* data;
} readcache;

static readcache* ReadCacheList;

void InitObjORL(void)
{
    ORLHandle = ORLInit(&ORLFuncs);
    ReadCacheList = NULL;
}

void ObjORLFini(void)
{
    ORLFini(ORLHandle);
}

static long ORLSeek(void* _list, long pos, int where)
{
    file_list* list = (file_list*)_list;

    if (where == SEEK_SET) {
        ORLFilePos = pos;
    }
    else if (where == SEEK_CUR) {
        ORLFilePos += pos;
    }
    else {
        ORLFilePos = list->file->len - pos;
    }
    return(ORLFilePos);
}

static void* ORLRead(void* _list, size_t len)
{
    return nullptr;
}