#include "pch.h"
#include "symtrace.h"
#include "MemorySubsystem.h"
#include "Structs.h"
#include "globals.h"

trace_info* CurrTrace;
trace_info* TraceList;

void ResetSymTrace()
{
    TraceList = NULL;
}
