#include "pch.h"
#include "globals.h"
#include "mem.h"
#include "ntio.h"
#include "wlnkmsg.h"
#include "objnode.h"
#include "objio.h"
#include "spillio.h"
#include "lsymbtab.h"

void InitSubSystems(void)
{
    LnkMemInit();
    LnkFilesInit();
    InitMsg();
    InitNodes();
    InitTokBuff();
    InitSpillFile();
    InitSym();
}

void LinkMainLine(char* cmds)
{
}

void FiniSubSystems(void)
{
    LnkMemFini();
}

int main(int argc, char* argv[])
{
    InitSubSystems();
    LinkMainLine(NULL);
    FiniSubSystems();
    return((LinkState & LINK_ERROR) ? 1 : 0);
}
