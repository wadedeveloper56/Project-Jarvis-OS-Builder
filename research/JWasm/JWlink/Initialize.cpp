#include "pch.h"
#include "Initialize.h"

#ifdef _INT_DEBUG
static  int     Chunks;
#endif
static int      OpenFiles;      // the number of open files
static unsigned LastResult;
static bool     CaughtBreak;    // set to TRUE if break hit.
bool BannerPrinted;

void LnkMemInit(void)
{
#ifdef _INT_DEBUG
    Chunks = 0;
#endif
}

void LnkFilesInit(void)
{
    OpenFiles = 0;
    CaughtBreak = false;
    _setmode(_fileno(stdin), O_BINARY);
    _setmode(_fileno(stdout), O_BINARY);
}

int InitMsg(void)
{
    BannerPrinted = false;
    return(EXIT_SUCCESS);
}

int FiniMsg(void)
{
    return(EXIT_SUCCESS);
}
