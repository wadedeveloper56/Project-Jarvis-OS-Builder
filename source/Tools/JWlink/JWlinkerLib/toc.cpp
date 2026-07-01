#include "pch.h"
#include "toc.h"
#include "Structs.h"
#include "globals.h"
#include "hash.h"

pHTable  Toc;
char* TocName;
symbol* TocSym;
offset TocSize;
offset TocShift;

void ResetToc()
{
    Toc = NULL;
    TocSize = 0;
    TocName = NULL;
    TocSym = NULL;
}

void CleanToc(void)
{
    ZapHTable(Toc);
}
