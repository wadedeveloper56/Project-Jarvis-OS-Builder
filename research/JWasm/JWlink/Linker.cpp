#include "pch.h"
#include "Linker.h"

Linker::Linker()
{
	file = new FileSubsystem();
	msg = new MessagingSubsystem(file);
	memory = new MemorySubsystem();
	InitSubSystems();
}

Linker::~Linker()
{
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
//    InitCmdFile();
}

void Linker::FiniSubSystems(void)
{
	FiniLinkStruct(memory);
	FiniMsg();
	FiniSym(memory);
	//LnkMemFini();
}

void Linker::mainLine()
{
}
