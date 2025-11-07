#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "alloc.h"
#include <pcobj.h>
#include "obj2supp.h"
#include "objnode.h"
#include "objcalc.h"
#include "objio.h"
#include "objcache.h"
#include "wcomdef.h"
#include "cmdline.h"
#include "loadfile.h"
#include "dbgall.h"
#include "objpass1.h"
#include "objstrip.h"
#include "omfreloc.h"
#include "carve.h"
#include "strtab.h"
#include "permdata.h"
#include "virtmem.h"
#include "impexp.h"
#include "objomf.h"
#include "specials.h"

/* forward declarations */

#if BORLAND_EXT==0
#define FindSegNode FindNode
#endif

byte            OMFAlignTab[] = { 0,0,1,4,8,2,12 };

extern lobject_data CurrRec;

enum dll_entry_type { DLL_RELOC_NAME, DLL_RELOC_ORDINAL };


void ResetObjOMF(void)
{
	//    ObjBuff = NULL;
	//    EOObjRec = NULL;
}