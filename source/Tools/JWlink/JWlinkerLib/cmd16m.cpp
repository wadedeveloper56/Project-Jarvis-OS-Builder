#include "pch.h"
#include "MemorySubsystem.h"
#include "cmd16m.h"
#include "globals.h"
#include "Structs.h"
#include "cmdline.h"

using namespace std;

void SetD16MFmt(shared_ptr<MemorySubsystem> memorySubsystem)
{
    LinkState &= ~MAKE_RELOCS;                  
    Extension = E_PROTECT;
    FmtData.u.d16m.options = 0;
    FmtData.u.d16m.flags = 0;
    FmtData.u.d16m.strategy = MNoStrategy;
    FmtData.u.d16m.buffer = 0;
    FmtData.u.d16m.gdtsize = 0xFFFF;            
    FmtData.u.d16m.selstart = D16M_USER_SEL;
    FmtData.u.d16m.extended = 0x7FFF;
    FmtData.u.d16m.datasize = 0x1000;
    FmtData.u.d16m.stub = NULL;
}

void FreeD16MFmt(shared_ptr<MemorySubsystem> memorySubsystem)
{
    memorySubsystem->FreeMemory(FmtData.u.d16m.stub);
}

