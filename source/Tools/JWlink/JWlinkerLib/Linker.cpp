#include "pch.h"
#include "Linker.h"
#include "debug.h"
#include "orl.h"
#include "Memory.h"
#include "Orl2.h"
#include "cmdline.h"
#include "objfree.h"
#include "ObjectNode.h"
#include "permdata.h"
#include "globals.h"
#include "libr.h"
#include "cmdutils.h"
#include "dbgall.h"
#include "mapio.h"
#include "cmdall.h"
#include "ovlsupp.h"
#include "wcomdef.h"
#include "distrib.h"
#include "loadnov.h"
#include "loadpe.h"
#include "obj2supp.h"
#include "objio.h"
#include "objomf.h"
#include "objpass1.h"
#include "objstrip.h"
#include "omfreloc.h"
#include "reloc.h"
#include "symtrace.h"
#include "loadfile.h"
#include "salloc.h"

Linker::Linker(int argc, char** argv)
{
	this->argc = argc;
	this->argv = argv;
	memorySubsystem = make_shared<MemorySubsystem>();
	fileSubsystem = make_shared<FileSubsystem>();
	messagingSubsystem = make_shared<MessagingSubsystem>();
	InitNodes(memorySubsystem);
	tokenBuffer = make_shared<TokenBuffer>(memorySubsystem);
	spillFile = make_shared<SpillFile>();
	symbolTable = make_shared<SymbolTable>(memorySubsystem);	
	orl = make_shared<Orl>();
	InitCmdFile();
	virtualMemory = make_shared<VirtualMemory>();
}

Linker::~Linker()
{
	FiniLinkStruct(memorySubsystem);	
}

void Linker::CleanSubSystems(void)
{
	DEBUG((DBG_OLD, "CleanSubSystems enter\n"));
	if (MapFile != NIL_HANDLE)
	{
	//	QClose(MapFile, MapFName);
		MapFile = NIL_HANDLE;
	}
	//FreeOutFiles();
	//_LnkFree(MapFName);
	//BurnSystemList();
	DEBUG((DBG_OLD, "CleanSubSystems: calling FreeList( LibPath )\n"));
	//FreeList(LibPath);
	//CloseSpillFile();
	//CleanTraces();
	//FreePaths();
	//FreeUndefs();
	//FreeLocalImports();
	DEBUG((DBG_OLD, "CleanSubSystems: calling CleanLoadFile()\n"));
	//CleanLoadFile();
	//CleanLinkStruct();
	//FreeFormatStuff();
	//FreeObjInfo();
	DEBUG((DBG_OLD, "CleanSubSystems: calling FreeVirtMem()\n"));
	//FreeVirtMem();
	//CleanToc();
	//CleanSym();
	//CleanPermData();
	DEBUG((DBG_OLD, "CleanSubSystems exit\n"));
}

void Linker::ResetMisc(void)
{
	LinkFlags = CASE_FLAG | FAR_CALLS_FLAG;
	LinkState = MAKE_RELOCS;
	AbsGroups = NULL;
	DataGroup = NULL;
	IDataGroup = NULL;
	MapFile = NIL_HANDLE;
	MapFName = NULL;
	OutFiles = NULL;
	ObjLibFiles = NULL;
	LibModules = NULL;
	Groups = NULL;
	CurrLoc.seg = UNDEFINED;
	CurrLoc.off = 0;
	OvlClasses = NULL;
	OvlVectors = NULL;
	VecNum = 0;
	OvlNum = 0;
	OvlFName = NULL;
	CurrMod = NULL;
	StackSize = 0x1000;
	// set case sensitivity for symbols
	symbolTable->ResetSym();
	symbolTable->SetSymCase();
	SetLibCase();
}

void Linker::ResetSubSystems(void)
{
	DEBUG((DBG_OLD, "ResetSubSystems enter\n"));
	ResetPermData(memorySubsystem);
	messagingSubsystem->reset();
	virtualMemory.reset();
	virtualMemory = make_shared<VirtualMemory>();
	ResetMisc();
	Root = NewSection(memorySubsystem);
	ResetDBI();
	ResetMapIO();
	ResetCmdAll();
	ResetOvlSupp();
	ResetComdef();
	ResetDistrib();
	ResetLoadNov();
	ResetLoadPE();
	ResetObj2Supp();
	ResetObjIO();
	ResetObjOMF();
	ResetObjPass1();
	ResetObjStrip();
	ResetOMFReloc();
	ResetReloc();
	ResetSymTrace();
	ResetLoadFile();
	ResetAddr();
	//ResetToc();
	DEBUG((DBG_OLD, "ResetSubSystems exit\n"));
}

void Linker::DoLink(char* cmdline)
{
}

void Linker::LinkMeBaby(void)
{
	ResetSubSystems();
	DoLink(ArgSave);
}

int Linker::Spawn(void (Linker::*fn)(void))
{
	void* save_env;
	jmp_buf env;
	int     status;

	save_env = SpawnStack;
	SpawnStack = env;
	status = setjmp(env);
	if (status == 0)
	{
		(this->*fn)();
	}
	SpawnStack = save_env;  /* unwind */
	return(status);
}	

int Linker::link(char* cmds)
{
	for (;;)
	{
		ArgSave = cmds;         // bogus way to pass args to spawn
		Spawn(&Linker::LinkMeBaby);
		CleanSubSystems();
		cmds = GetNextLink();
		if (cmds == NULL) break;
	}
    return((LinkState & LINK_ERROR) ? 1 : 0);
}
