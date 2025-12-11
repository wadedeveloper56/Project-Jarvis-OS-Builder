#include "pch.h"
#include "globals.h"
#include "loados2.h"

void FreeImpNameTab(void)
{
    FmtData.u.os2.mod_ref_list = NULL;  /* these are permalloc'd */
    FmtData.u.os2.imp_tab_list = NULL;
}