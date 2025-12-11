#include "pch.h"
#include "globals.h"
#include "impexp.h"
#include "carve.h"
#include "mem.h"
#include "permdata.h"

static entry_export* FreeAnExport(entry_export* exp)
/****************************************************/
{
    entry_export* next;

    _LnkFree(exp->impname);
    next = exp->next;
    CarveFree(CarveExportInfo, exp);
    return(next);
}

void FreeExportList(void)
/********************************/
{
    entry_export* exp;

    if (LinkFlags & INC_LINK_FLAG) return;
    exp = FmtData.u.os2.exports;
    while (exp != NULL) {
        exp = FreeAnExport(exp);
    }
}
