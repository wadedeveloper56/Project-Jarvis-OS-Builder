#include "pch.h"
#include "Linker.h"

Linker::Linker()
{
	file = new FileSubsystem();
	msg = new MessagingSubsystem(file);
	memory = new MemorySubsystem();
	InitSubSystems();
    ResetSubSystems();
}

Linker::~Linker()
{
    CleanSubSystems();
	FiniSubSystems();
	delete memory;
	delete msg;
	delete file;
}

void Linker::InitSubSystems(void)
{
#ifdef _INT_DEBUG
    memset(_edata, 0xA5, _end - _edata);      // don't rely on BSS == 0
#endif
    LnkMemInit();
    LnkFilesInit();
    InitMsg();
    InitNodes(memory);
    InitTokBuff(memory);
    InitSpillFile();
    InitSym(memory);
    InitObjORL(memory);
    InitCmdFile();
}

void Linker::ResetSubSystems(void)
{
    ResetPermData(memory);
    //ResetMsg();
    //VirtMemInit();
    ResetMisc();
    Root = NewSection(memory);
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
    ResetToc();
}

void Linker::CleanSubSystems(void)
{
    if (MapFile != NIL_HANDLE) {
        file->Close(MapFile);
        MapFile = NIL_HANDLE;
    }
    FreeOutFiles(file, memory);
    _LnkFree(MapFName);
    BurnSystemList(memory);
    FreeList(memory, LibPath);
    CloseSpillFile(file, memory);
    CleanTraces(memory);
    FreePaths(memory);
    FreeUndefs(memory);
    FreeLocalImports();
    CleanLoadFile();
    CleanLinkStruct(msg, file, memory);
    FreeFormatStuff();
    FreeObjInfo();
    FreeVirtMem(memory);
    CleanToc(memory);
    CleanSym(msg, memory);
    CleanPermData(msg, memory, file);
}

void Linker::FiniSubSystems(void)
{
	FiniLinkStruct(memory);
	FiniMsg();
	FiniSym(memory);
	LnkMemFini();
}

void Linker::mainLine()
{
}
