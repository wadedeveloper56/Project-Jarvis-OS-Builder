#include "pch.h"
#include "objstruct.h"
#include "alloc.h"

static trace_info* CurrTrace;
trace_info* TraceList;

void ResetSymTrace(void)
{
    TraceList = NULL;
}

void CleanTraces(void)
{
    trace_info* next;

    while (TraceList != NULL) {
        next = TraceList->next;
        if (!TraceList->found) {
            _LnkFree(TraceList->u.name);
        }
        _LnkFree(TraceList->member);
        _LnkFree(TraceList);
        TraceList = next;
    }
    TraceList = NULL;
}
