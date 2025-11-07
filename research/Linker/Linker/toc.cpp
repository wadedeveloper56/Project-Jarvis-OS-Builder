#include "pch.h"
#include "linkstd.h"
#include "toc.h"
#include "hash.h"
#include "alloc.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "virtmem.h"
#include "reloc.h"
#include "obj2supp.h"
#include "loadpe.h"
#include "loadfile.h"
#include "specials.h"
#include "objpass1.h"
#include "objstrip.h"

#define BOGUS  0xa5a5a5a5

static pHTable  Toc;
static char* TocName;
static symbol* TocSym;

offset TocSize;
offset TocShift;

typedef struct {
    segdata* sdata;    // If sdata == NULL, use sym to get address
    // else use off and sdata->addr get address
    union {
        offset off;  // relative to sdata->addr
        symbol* sym;
    } u;
} TocEntryId;

typedef struct {
    TocEntryId e;
    int pos;
} TocEntry;


void ResetToc(void)
{
    Toc = NULL;
    TocSize = 0;
    TocName = NULL;
    TocSym = NULL;
}
