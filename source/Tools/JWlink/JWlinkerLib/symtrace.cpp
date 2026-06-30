#include "pch.h"
#include "symtrace.h"
#include "MemorySubsystem.h"
#include "Structs.h"
#include "globals.h"

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