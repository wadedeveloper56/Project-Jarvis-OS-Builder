#include "pch.h"
#include "globals.h"
#include "cmdqnx.h"
#include "link.h"
#include "command.h"
#include "objfree.h"
#include "cmdos2.h"

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

void FreeELFFmt(void)
{
    /*  FreeList( FmtData.u.elf.exp.export );
        FreeList( FmtData.u.elf.exp.module ); Permalloc'd now */
}