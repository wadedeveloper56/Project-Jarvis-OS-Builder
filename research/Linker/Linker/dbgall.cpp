#include "pch.h"
#include "linkstd.h"
#include "alloc.h"
#include "specials.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "fileio.h"
#include "virtmem.h"
#include "exeelf.h"
#include "objcalc.h"
#include "loadfile.h"
#include "objio.h"
#include "dbgcomm.h"
#include "dbgall.h"
#include "dbgcv.h"
#include "objfree.h"
#include "overlays.h"
#include "dbgdwarf.h"
#include "dbgwat.h"
#include "ring.h"
#include "loadnov.h"

char* SymFileName;
group_entry* DBIGroups;

void ResetDBI(void)
{
    SymFileName = NULL;
    DBIGroups = NULL;
}
