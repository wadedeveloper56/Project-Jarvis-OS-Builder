#include "pch.h"
#include "objcache.h"
#include "Structs.h"
#include "globals.h"
#include "MemorySubsystem.h"
#include "debug.h"
#include "ntio.h"
#include "objio.h"

using namespace std;

bool CacheOpen(shared_ptr<MemorySubsystem> memorySubsystem, file_list* list)
{
    infilelist* file;

    if (list == NULL) return true;
    file = list->file;
    if (file->flags & INSTAT_IOERR) return false;
    if (DoObjOpen(file))
    {
        DO_OR_EQUAL(infile_flags, file->flags, |=, INSTAT_IN_USE)
    }
    else
    {
        DO_OR_EQUAL(infile_flags, file->flags, |=, INSTAT_IOERR)
        return(false);
    }
    if (file->len == 0)
    {
        file->len = QFileSize(file->handle);
        if (file->len == 0)
        {
            DEBUG((DBG_OLD, "CacheOpen: bad object error\n"));
            //LnkMsg(ERR + MSG_BAD_OBJECT, "s", file->name);
            DO_OR_EQUAL(infile_flags, file->flags, |=, INSTAT_IOERR)//; file->flags |= INSTAT_IOERR;
            return(false);
        }
    }
    if (file->cache == NULL)
    {
        file->cache = (char*)memorySubsystem->AllocateMemory(file->len);
        if (file->currpos != 0)
        {
            QLSeek(file->handle, 0, SEEK_SET, file->name);
        }
        QRead(file->handle, file->cache, file->len, file->name);
        file->currpos = file->len;
    }
    return true;
}

void CacheClose(shared_ptr<MemorySubsystem> memorySubsystem, file_list* list, unsigned pass)
{
    infilelist* file;

    if (list == NULL) return;
    file = list->file;
    DO_AND_EQUAL(infile_flags, file->flags, &=, ~INSTAT_IN_USE);
    switch (pass)
    {
        case 1:    
        case 2:    
            if (!(file->flags & INSTAT_LIBRARY))
            {
                memorySubsystem->FreeMemory(file->cache);
                file->cache = NULL;
            }
            break;
        case 3:    
            if (file->handle != NIL_HANDLE)
            {
                QClose(file->handle, file->name);
                file->handle = NIL_HANDLE;
            }
            if (file->cache != NULL)
            {
                memorySubsystem->FreeMemory(file->cache);
                file->cache = NULL;
            }
            break;
    }
}

void* CachePermRead(file_list* list, unsigned long pos, unsigned len)
{
    return CacheRead(list, pos, len);
}

void* CacheRead(file_list* list, unsigned long pos, unsigned len)
{
    if (pos + len > list->file->len) return NULL;
    return (char*)list->file->cache + pos;
}

bool CacheEnd(file_list* list, unsigned long pos)
{
    return pos >= list->file->len;
}

void CacheFini(void)
{
}

void CacheFree(file_list* list, void* blk)
{
    list = list;
    blk = blk;
}

void FreeObjCache(file_list* list)
{
    list = list;
}

bool DumpObjCache(void)
{
    return false;
}
