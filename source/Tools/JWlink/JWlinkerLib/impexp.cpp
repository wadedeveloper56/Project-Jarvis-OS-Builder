#include "pch.h"
#include "impexp.h"
#include "Structs.h"
#include "MemorySubsystem.h"
#include "globals.h"
#include "carve.h"
#include "permdata.h"

void FreeImport(dll_sym_info* dll)
{
    CarveFree(CarveDLLInfo, dll);
}
