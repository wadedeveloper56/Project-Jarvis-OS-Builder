#include "pch.h"
#include "objio.h"
#include "Structs.h"
#include "globals.h"
#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"
#include "ntio.h"
#include "strtab.h"
#include "permdata.h"
#include "linkutil.h"

using namespace std;

infilelist* CachedLibFiles;
infilelist* CachedFiles;

void ResetObjIO()
{
    CachedFiles = NULL;
    CachedLibFiles = NULL;
}

infilelist* AllocEntry(MemorySubsystem *memorySubsystem, char* name, path_entry* path)
{
    infilelist* entry = (infilelist*)memorySubsystem->AllocateMemory(sizeof(infilelist));
    entry->name = AddStringStringTable(memorySubsystem, &PermStrings, name);
    entry->path_list = path;
    entry->prefix = NULL;
    entry->handle = NIL_HANDLE;
    entry->cache = NULL;
    entry->len = 0;
    entry->flags = (infile_flags)0;
    return entry;
}

infilelist* AllocFileEntry(MemorySubsystem *memorySubsystem, char* name, path_entry* path)
{
    infilelist* entry;

    entry = AllocEntry(memorySubsystem, name, path);
    entry->next = CachedFiles;
    CachedFiles = entry;
    return entry;
}

infilelist* AllocUniqueFileEntry(MemorySubsystem *memorySubsystem, char* name, path_entry* path)
{
    infilelist* entry;

    for (entry = CachedLibFiles; entry != NULL; entry = entry->next)
    {
        if (FNAMECMPSTR(entry->name, name) == 0)
        {
            return entry;              
        }
    }
    entry = AllocEntry(memorySubsystem, name, path);
    if (CachedLibFiles == NULL)
    {             
        CachedLibFiles = entry;             
        LinkList(&CachedFiles, entry);
    }
    else
    {
        LinkList(&CachedLibFiles, entry);
    }
    return entry;
}

bool CleanCachedHandles()
{
    infilelist* list;

    for (list = CachedFiles; list != NULL; list = list->next)
    {
        if (!(list->flags & INSTAT_IN_USE) && list->handle != NIL_HANDLE)break;
    }
    if (list == NULL) return(false);
    QClose(list->handle, list->name);
    list->handle = NIL_HANDLE;
    return(true);
}

#define LIB_SEARCH (INSTAT_USE_LIBPATH | INSTAT_LIBRARY)

f_handle PathObjOpen(FileSubsystem* fileSubsystem, char* path_ptr, char* name, char* new_name, infilelist* list)
{
    f_handle    fp;

    fp = NIL_HANDLE;
    for (;;)
    {
        list->prefix = path_ptr;
        if (!QMakeFileName(&path_ptr, name, new_name)) break;
        fp = QObjOpen(fileSubsystem, new_name);
        if (fp != NIL_HANDLE) break;
    }
    return fp;
}

f_handle TrySearchingLib(FileSubsystem* fileSubsystem, char* name, char* new_name, infilelist* list)
{
    f_handle            fp;

    fp = NIL_HANDLE;
    if (list->flags & INSTAT_USE_LIBPATH)
    {
        fp = PathObjOpen(fileSubsystem, getenv("LIB"), name, new_name, list);
    }
    return fp;
}

bool DoObjOpen(FileSubsystem* fileSubsystem, infilelist* list)
{
    char* name;
    f_handle    fp;
    //unsigned    err;
    char* path_ptr;
    char        new_name[PATH_MAX];
    path_entry* searchpath;
    bool        haspath;

    name = list->name;
    if (list->handle != NIL_HANDLE) return(true);
    list->currpos = 0;
    haspath = QHavePath(name);
    if (list->path_list == NULL || haspath)
    {
        list->path_list = NULL;
        fp = QObjOpen(fileSubsystem, name);
        if (fp == NIL_HANDLE && !haspath)
        {
            fp = TrySearchingLib(fileSubsystem, name, new_name, list);
        }
    }
    else if (list->prefix != NULL)
    {
        path_ptr = list->prefix;
        QMakeFileName(&path_ptr, name, new_name);
        fp = QObjOpen(fileSubsystem, new_name);
    }
    else
    {
        fp = NIL_HANDLE;
        if (list->flags & LIB_SEARCH)
        {
            fp = QObjOpen(fileSubsystem, name);
        }
        if (fp == NIL_HANDLE)
        {
            searchpath = list->path_list;
            for (;;)
            {
                fp = PathObjOpen(fileSubsystem, searchpath->name, name, new_name, list);
                if (fp != NIL_HANDLE || !(list->flags & LIB_SEARCH)) break;
                searchpath = searchpath->next;
                if (searchpath == NULL)
                {
                    fp = TrySearchingLib(fileSubsystem, name, new_name, list);
                    break;
                }
            }
        }
    }
    if (fp != NIL_HANDLE)
    {
        if (!(list->flags & INSTAT_GOT_MODTIME))
        {
            list->modtime = QFModTime(fp);
        }
        list->handle = fp;
        return true;
    }
    else if (!(list->flags & INSTAT_NO_WARNING))
    {
        //err = (list->flags & INSTAT_OPEN_WARNING) ?  WRN + MSG_CANT_OPEN : ERR + MSG_CANT_OPEN;
        //PrintIOError(err, "12", name);
        list->prefix = NULL;
        list->handle = NIL_HANDLE;
    }
    return true;
}

uint16_t CalcAlign(uint32_t pos, uint16_t align)
{
    uint16_t modulus;

    modulus = pos % align;
    if (modulus != 0)
    {
        modulus = align - modulus;     
    }
    return(modulus);
}

void InitTokBuff(MemorySubsystem *memorySubsystem)
{
    TokSize = MAX_HEADROOM;
    TokBuff = (char*)memorySubsystem->AllocateMemory(MAX_HEADROOM);
}

void FreeTokBuffs(MemorySubsystem *memorySubsystem)
{
    if (TokBuff != NULL)
    {
        memorySubsystem->FreeMemory(TokBuff);
        TokBuff = NULL;
    }
}

void BadObject()
{
    DO_OR_EQUAL(infile_flags, CurrMod->f.source->file->flags, |=, INSTAT_IOERR)//CurrMod->f.source->file->flags |= INSTAT_IOERR;
    //LnkMsg(LOC + ERR + MSG_OBJ_FILE_ATTR, NULL);
}

void EarlyEOF(MessagingSubsystem*messagingSubsystem)
{
    DO_OR_EQUAL(infile_flags, CurrMod->f.source->file->flags, |=, INSTAT_IOERR)//CurrMod->f.source->file->flags |= INSTAT_IOERR;
    messagingSubsystem->Locator(CurrMod->f.source->file->name, NULL, 0);
    //LnkMsg(ERR + MSG_EARLY_EOF, NULL);
}

