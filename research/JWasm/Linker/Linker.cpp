#include "pch.h"
#include "Linker.h"
#include "globals.h"
#include "libr.h"
#include "CmdUtils.h"
#include "dbgall.h"
#include "cmdall.h"
#include "ovlsupp.h"
#include "comdef.h"
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
#include "SAlloc.h"
#include "toc.h"

Linker::Linker()
{
	LinkState = 0;
	memory = new MemorySubsystem();
	file = new FileSubsystem();
	messaging = new MessagingSubsystem(file);
	hashTable = new HashTable(memory);
	nodes = new Node(memory);
	tokenBuffer = new TokenBuffer(memory);
	spillFile = new SpillFile(file, memory);
	symbolTable = new SymbolTable(memory);
	objorl = new ObjOrl(memory, file, tokenBuffer);
	cmdLine = new CmdLine(memory);
	ring = new Ring(memory);
	carve = new Carve(memory);
	strtab = new StringTable(memory, ring);
	permData = new PermData(memory, ring, carve, strtab);
	virtMem = new VirtualMemory(memory);
	mapio = new MapIO();
}

Linker::~Linker()
{
	delete mapio;
	delete virtMem;
	delete permData;
	delete strtab;
	delete carve;
	delete ring;
	delete cmdLine;
	delete objorl;
	delete symbolTable;
	delete spillFile;
	delete tokenBuffer;
	delete nodes;
	delete hashTable;
	delete messaging;
	delete file;
	delete memory;
}

void Linker::ResetMisc(void)
{
	/* jwlink: default is: multiple defines are NOT ok */
	//LinkFlags = REDEFS_OK | CASE_FLAG | FAR_CALLS_FLAG;
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
	permData->Reset();
	messaging->ResetMsg();
	ResetMisc();
	Root = NewSection(memory, hashTable);
	ResetDBI();
	mapio->ResetMapIO();
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
	ResetToc();
}

void Linker::CleanSubSystems()
{
	if (MapFile != NIL_HANDLE) {
		CloseFile(MapFile);
		MapFile = NIL_HANDLE;
	}
	FreeOutFiles(memory);
	memory->FreeMemory(MapFName);
	cmdLine->BurnSystemList();
	virtMem->FreeList(LibPath);
	//CleanTraces();
	//FreePaths();
	//FreeUndefs();
	//FreeLocalImports();
	//CleanLoadFile();
	//CleanLinkStruct();
	//FreeFormatStuff();
	//FreeObjInfo();
	//FreeVirtMem();
	CleanToc();
	//CleanSym();
	//CleanPermData();
}

void Linker::doLink(void)
{
	// The main linking process would be implemented here.
	// This is a placeholder for the actual linking logic.
}

void Linker::mainLine()
{
	ResetSubSystems();
	doLink();
	CleanSubSystems();
}
