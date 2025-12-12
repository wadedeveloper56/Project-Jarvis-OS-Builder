#include "pch.h"
#include "globals.h"
#include "cmdelf.h"
#include "cmdline.h"

void SetELFFmt(void)
/***************************/
{
    Extension = E_ELF;
    FmtData.u.elf.exp.export1 = nullptr;
    FmtData.u.elf.exp.module = nullptr;
    FmtData.u.elf.extrasects = 0;
    FmtData.u.elf.segment_shift = 0;
    FmtData.u.elf.abitype = 0;
    FmtData.u.elf.abiversion = 0;
}

void FreeELFFmt(void)
/****************************/
{
    /*  FreeList( FmtData.u.elf.exp.export );
        FreeList( FmtData.u.elf.exp.module ); Permalloc'd now */
}