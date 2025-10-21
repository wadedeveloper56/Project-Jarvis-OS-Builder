#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "wlink.h"

void LnkMemInit()
{
}

void LnkFilesInit()
{
}

void InitMsg()
{
}

void InitNodes()
{
}

void InitTokBuff()
{
}

void InitSpillFile()
{
}

void InitSym()
{
}

void InitObjORL()
{
}

void InitCmdFile()
{
}


void InitSubSystems(void)
{
#ifdef _INT_DEBUG
    memset(_edata, 0xA5, _end - _edata);      // don't rely on BSS == 0
#endif
    LnkMemInit();
    LnkFilesInit();
    InitMsg();
    InitNodes();
    InitTokBuff();
    InitSpillFile();
    InitSym();
    InitObjORL();
    InitCmdFile();
}

int main(int argc, char** argv)
{
	InitSubSystems();
	//LinkMainLine(NULL);
	//FiniSubSystems();
	return 0;
}
