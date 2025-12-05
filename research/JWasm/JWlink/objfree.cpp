#include "pch.h"
#include "debug.h"
#include "objnode.h"
#include "objio.h"
#include "mixcache.h"
#include "objorl.h"

void FiniLinkStruct(void)
{
    DEBUG((DBG_OLD, (char *)"FiniLinkStruct()"));
    BurnNodes();
    FreeTokBuffs();
    CacheFini();
    ObjORLFini();
}