#include "pch.h"
#include "Linker.h"
#include "orl2.h"
#include "Memory.h"
#include "Orl2.h"
#include "cmdline.h"

void InitNodes(shared_ptr<MemorySubsystem> memorySubsystem);
void BurnNodes(shared_ptr<MemorySubsystem> memorySubsystem);

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
}

Linker::~Linker()
{
	BurnNodes(memorySubsystem);
}

void Linker::CleanSubSystems(void)
{
}

void Linker::ResetSubSystems(void)
{
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
