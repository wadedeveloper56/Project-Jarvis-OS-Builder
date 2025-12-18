#include "pch.h"
#include "CmdLine.h"

CmdLine::CmdLine(MemorySubsystem* memory)
{
	this->memory = memory;
	PrevCommand = nullptr;
	SysBlocks = nullptr;
}

CmdLine::~CmdLine()
{
}

void CmdLine::CleanSystemList(bool check)
{
    sysblock** sys;
    sysblock* next;
    char* name;

    sys = &SysBlocks;
    while (*sys != NULL) {
        name = (*sys)->name;
        if (!check || (memcmp("286", name, 4) != 0 && memcmp("386", name, 4) != 0)) {
            next = (*sys)->next;
            memory->FreeMemory(name);
            memory->FreeMemory(*sys);
            *sys = next;
        }
        else {
            sys = &(*sys)->next;
        }
    }
}

void CmdLine::BurnSystemList(void)
{
	CleanSystemList(false);
}