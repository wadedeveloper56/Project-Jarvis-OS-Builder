#include "pch.h"
#include "cmdall.h"
#include "globals.h"
#include "Structs.h"
#include "debug.h"
#include "objio.h"
#include "MemorySubsystem.h"

void* LastFile;
file_list** LastLibFile;

void ResetCmdAll()
{
    LastFile = NULL;
    LastLibFile = NULL;
    LibPath = NULL;
}

file_list* AllocNewFile(MemorySubsystem* memorySubsystem, member_list* member)
{
    file_list* new_entry=NULL;

    _LnkAlloc(file_list*, new_entry, sizeof(file_list));
    new_entry->next_file = NULL;
    new_entry->status = (file_status)DBIFlag;
    new_entry->strtab = NULL;
    new_entry->u.member = member;
    if (member != NULL)
    {
        DO_OR_EQUAL(file_status, new_entry->status, |=, STAT_HAS_MEMBER);
    }
    return(new_entry);
}

file_list* AddObjLib(MemorySubsystem* memorySubsystem, char* name, lib_priority priority)
{
    file_list** next_owner;
    file_list** proc_owner;
    file_list* proc_curr;
    file_list* newproc=NULL;
    bool        added;

    DEBUG((DBG_OLD, "Adding Object library name %s", name));
    proc_owner = &ObjLibFiles;
    for (;;)
    {
        proc_curr = *proc_owner;
        if (proc_curr == NULL)
            break;
        if (proc_curr->priority < priority)
            break;
        if (FNAMECMPSTR(proc_curr->file->name, name) == 0)
            return(proc_curr);
        proc_owner = (file_list**) & proc_curr->next_file;
    }

    added = TRUE;
    next_owner = proc_owner;                  
    for (;;)
    {                                      
        if (proc_curr == NULL)
            break;
        if (FNAMECMPSTR(proc_curr->file->name, name) == 0)
        {
            *next_owner = (file_list*)proc_curr->next_file;
            proc_curr->next_file = (FILE_LIST*)*proc_owner;
            *proc_owner = proc_curr;
            proc_curr->priority = priority;
            newproc = proc_curr;
            added = FALSE;
            break;
        }
        next_owner = (file_list**) & proc_curr->next_file;
        proc_curr = *next_owner;
    }
    if (added)
    {          
        newproc = AllocNewFile(memorySubsystem, NULL);
        newproc->file = AllocUniqueFileEntry(memorySubsystem, name, LibPath);
        DO_OR_EQUAL(infile_flags, newproc->file->flags, |=, INSTAT_LIBRARY | INSTAT_OPEN_WARNING);
        newproc->priority = priority;
        newproc->next_file = (FILE_LIST*)*proc_owner;
        *proc_owner = newproc;
        LinkState |= LIBRARIES_ADDED;
    }
    return(newproc);
}


