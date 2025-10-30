#include "pch.h"
#include "globals.h"
#include "mem.h"
#include "ntio.h"
#include "wlnkmsg.h"

void InitSubSystems(void)
{
    LnkMemInit();
    LnkFilesInit();
    InitMsg();
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
