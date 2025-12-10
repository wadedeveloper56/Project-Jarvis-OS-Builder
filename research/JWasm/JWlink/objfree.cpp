#include "pch.h"
#include "globals.h"
#include "objfree.h"
#include "objnode.h"
#include "objio.h"
#include "mixcache.h"
#include "objorl.h"
#include "debug.h"

void FiniLinkStruct(void)
{
    DEBUG((DBG_OLD, "FiniLinkStruct()"));
    BurnNodes();
    FreeTokBuffs();
    CacheFini();
    ObjORLFini();
}
