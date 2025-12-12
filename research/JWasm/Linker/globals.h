#pragma once

#include "types.h"
#include "structures.h"

extern stateflag      LinkState;      /* flags to indicate linker state */
extern int            RecNum;         /* record number of the obj file        */
extern tok             Token;
extern mod_entry* CurrMod;        /* pointer to current mod_entry struct  */
extern cmdfilelist* CmdFile;
extern linkflag       LinkFlags;      /* flags to indicate presence of parms  */
