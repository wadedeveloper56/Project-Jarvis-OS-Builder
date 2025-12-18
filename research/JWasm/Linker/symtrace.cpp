#include "pch.h"
#include "globals.h"
#include "symtrace.h"

static trace_info* CurrTrace;
trace_info* TraceList;

void ResetSymTrace(void)
{
    TraceList = NULL;
}