#include "globals.h"

stateflag      LinkState;      /* flags to indicate linker state */
int            RecNum;         /* record number of the obj file        */
tok             Token;
mod_entry* CurrMod;        /* pointer to current mod_entry struct  */
cmdfilelist* CmdFile = NULL;
linkflag       LinkFlags;      /* flags to indicate presence of parms  */
