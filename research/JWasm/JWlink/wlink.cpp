#include "pch.h"
#include "globals.h"
#include "alloc.h"
#include "mem.h"
#include "ntio.h"
#include "wlnkmsg.h"
#include "objnode.h"
#include "objio.h"
#include "spillio.h"
#include "lsymtab.h"
#include "objorl.h"
#include "command.h"
#include "objfree.h"
#include "linkutil.h"
#include "loadfile.h"
#include "symtrace.h"

static char* ArgSave;

void InitSubSystems(void)
{
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

static void LinkMeBaby(void)
{
}

static void CleanSubSystems(void)
{
	if (MapFile != NIL_HANDLE) {
		QClose(MapFile, MapFName);
		MapFile = NIL_HANDLE;
	}
	FreeOutFiles();
	_LnkFree(MapFName);
	BurnSystemList();
	FreeList(LibPath);
	CloseSpillFile();
	CleanTraces();
	FreePaths();
	//FreeUndefs();
	//FreeLocalImports();
	//CleanLoadFile();
	//CleanLinkStruct();
	//FreeFormatStuff();
	//FreeObjInfo();
	//FreeVirtMem();
	//CleanToc();
	//CleanSym();
	//CleanPermData();
}

void LinkMainLine(char* cmds)
{
	for (;;) {
		ArgSave = cmds;         // bogus way to pass args to spawn
		Spawn(&LinkMeBaby);
		CleanSubSystems();
		cmds = GetNextLink();
		if (cmds == NULL) break;
	}
}

void FiniSubSystems(void)
{
	FiniLinkStruct();
	FiniMsg();
	FiniSym();
	LnkMemFini();
}

int main(int argc, char** argv)
{
	_argv = argv;
	_argc = argc;
	InitSubSystems();
	LinkMainLine(NULL);
	FiniSubSystems();
	return((LinkState & LINK_ERROR) ? 1 : 0);
}