#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "library.h"
#include "overlays.h"
#include "symtrace.h"

static trace_info* CurrTrace;

trace_info* TraceList;

void ResetSymTrace(void)
{
    TraceList = NULL;
}
