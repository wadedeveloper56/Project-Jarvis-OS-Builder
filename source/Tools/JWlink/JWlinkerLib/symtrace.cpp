#include "pch.h"
#include "symtrace.h"
#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"
#include "Structs.h"
#include "globals.h"
#include "reloc.h"

using namespace std;

trace_info* CurrTrace;
trace_info* TraceList;

void ResetSymTrace()
{
    TraceList = NULL;
}

void CleanTraces(MemorySubsystem *memorySubsystem)
{
    trace_info* next;

    while (TraceList != NULL)
    {
        next = TraceList->next;
        if (!TraceList->found)
        {
            memorySubsystem->FreeMemory(TraceList->u.name);
        }
        memorySubsystem->FreeMemory(TraceList->member);
        memorySubsystem->FreeMemory(TraceList);
        TraceList = next;
    }
    TraceList = NULL;
}

void CheckFileTrace(MemorySubsystem *memorySubsystem, SpillFile* spillFile, section* sect)
{
    file_list* list;

    if (CurrTrace->found)
        return;
    for (list = sect->files; list != NULL; list = list->next_file)
    {
        if (FNAMECMPSTR(list->file->name, CurrTrace->u.name) == 0)
        {
            CurrTrace->found = TRUE;
            _LnkFree(CurrTrace->u.name);
            DO_OR_EQUAL(file_status, list->status, |=, STAT_TRACE_SYMS);  //list->status |= STAT_TRACE_SYMS;
            return;
        }
    }
}

void CheckTraces(MemorySubsystem *memorySubsystem, SpillFile* spillFile, MessagingSubsystem *messagingSubsystem)
{
    trace_info* info;
    trace_info* next;
    file_list* lib;
    trace_info** prev;

    prev = &TraceList;
    for (info = TraceList; info != NULL; info = next)
    {
        next = info->next;
        if (info->member == NULL)
        {
            CurrTrace = info;
            WalkAllSects(memorySubsystem, spillFile, CheckFileTrace);
            if (!info->found)
            {
                messagingSubsystem->LnkMsg(WRN + MSG_TRACE_OBJ_NOT_FOUND, "s", info->u.name);
                _LnkFree(info->u.name);
            }
            _LnkFree(info);
        }
        else
        {
            for (lib = ObjLibFiles; lib != NULL; lib = lib->next_file)
            {
                if (FNAMECMPSTR(lib->file->name, info->u.name) == 0)
                {
                    info->found = TRUE;
                    _LnkFree(info->u.name);
                    info->u.lib = lib;
                    break;
                }
            }
            *prev = info;
            prev = &info->next;
        }   
    }   
    *prev = NULL;
}


