#include "pch.h"
#include "globals.h"
#include "symtrace.h"

static trace_info* CurrTrace;
trace_info* TraceList;

void ResetSymTrace(void)
{
    TraceList = nullptr;
}

void CleanTraces(MemorySubsystem* memory)
{
    trace_info* next;

    while (TraceList != nullptr) {
        next = TraceList->next;
        if (!TraceList->found) {
            memory->FreeMemory(TraceList->u.name);
        }
        memory->FreeMemory(TraceList->member);
        memory->FreeMemory(TraceList);
        TraceList = next;
    }
    TraceList = nullptr;
}
