#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "alloc.h"
#include "reloc.h"
#include "objnode.h"
#include "overlays.h"
#include "library.h"
#include "virtmem.h"
#include "objcache.h"
#include "loados2.h"
#include "dbgall.h"
#include "objio.h"
#include "wcomdef.h"
#include "objorl.h"
#include "loadfile.h"
#include "ring.h"
#include "carve.h"
#include "strtab.h"
#include "permdata.h"
#include "objpass1.h"
#include "objpass2.h"
#include "objfree.h"

static void FreeAreas(OVL_AREA* area);
static void FreeClasses(class_entry* list);
static void FreeFiles(file_list* list);
static void FreeMods(mod_entry* head);

void FiniLinkStruct(void)
{
    DEBUG((DBG_OLD, "FiniLinkStruct()"));
    BurnNodes();
    FreeTokBuffs();
    CacheFini();
    ObjORLFini();
}