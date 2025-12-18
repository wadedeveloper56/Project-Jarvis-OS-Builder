#include "pch.h"
#include "globals.h"
#include "toc.h"


#define BOGUS  0xa5a5a5a5

//static pHTable  Toc;
static char* TocName;
static symbol* TocSym;

offset TocSize;
offset TocShift;

typedef struct {
    segdata* sdata;    // If sdata == nullptr, use sym to get address
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
    //Toc = nullptr;
    TocSize = 0;
    TocName = nullptr;
    TocSym = nullptr;
}

void CleanToc(void)
{
    //ZapHTable(Toc, LFree);
}