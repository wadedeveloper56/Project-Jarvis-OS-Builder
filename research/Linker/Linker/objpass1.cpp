#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "specials.h"
#include "objnode.h"
#include "objcalc.h"
#include "dbgall.h"
#include "exeos2.h"
#include "overlays.h"
#include "mapio.h"
#include "cmdline.h"
#include "objstrip.h"
#include "cmdnov.h"
#include "cmdelf.h"
#include "impexp.h"
#include "ring.h"
#include "strtab.h"
#include "carve.h"
#include "permdata.h"
#include "virtmem.h"
#include "obj2supp.h"
#include "objpass2.h"
#include "objpass1.h"
#include "loadpe.h"

#define MAX_SEGMENT         0x10000

static seg_leader* LastCodeSeg;    // last code segment in current module

void ResetObjPass1(void)
{
    ObjFormat = (obj_format)0;
}
