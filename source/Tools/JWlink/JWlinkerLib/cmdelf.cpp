#include "pch.h"
#include "cmdelf.h"
#include "MemorySubsystem.h"
#include "globals.h"
#include "Structs.h"
#include "cmdline.h"

using namespace std;


void SetELFFmt(void)
{
    Extension = E_ELF;
    FmtData.u.elf.exp.export1 = NULL;
    FmtData.u.elf.exp.module = NULL;
    FmtData.u.elf.extrasects = 0;
    FmtData.u.elf.segment_shift = 0;
    FmtData.u.elf.abitype = 0;
    FmtData.u.elf.abiversion = 0;
}

void FreeELFFmt(shared_ptr<MemorySubsystem> memorySubsystem)
{
    /*  FreeList( FmtData.u.elf.exp.export );
        FreeList( FmtData.u.elf.exp.module ); Permalloc'd now */
}
