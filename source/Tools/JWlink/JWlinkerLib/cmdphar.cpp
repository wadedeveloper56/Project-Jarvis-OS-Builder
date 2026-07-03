#include "pch.h"
#include <memory>
#include "MemorySubsystem.h"
#include "cmdline.h"
#include "Structs.h"
#include "globals.h"
#include "Linkutil.h"
#include "cmd16m.h"
#include "cmdqnx.h"
#include "cmdelf.h"
#include "cmdos2.h"
#include "cmdphar.h"
#include "cmdline.h"
#include "objfree.h"

using namespace std;

void SetPharFmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem)
{
    Extension = E_PROTECT;
    LinkState &= ~MAKE_RELOCS;     // do not generate relocations.
    FmtData.u.phar.params = (rtpblock*)memorySubsystem->AllocateMemory(sizeof(*FmtData.u.phar.params));
    FmtData.u.phar.mindata = 0;
    FmtData.u.phar.maxdata = 0xFFFFFFFF;
    FmtData.u.phar.breaksym = NULL;
    FmtData.u.phar.stub = NULL;
    //  FmtData.u.phar.pack = FALSE;
    FmtData.u.phar.params->minreal = 0;
    FmtData.u.phar.params->maxreal = 0;
    FmtData.u.phar.params->callbufs = 0;
    FmtData.u.phar.params->realbreak = 0;
    FmtData.u.phar.params->minibuf = 1;
    FmtData.u.phar.params->maxibuf = 4;
    FmtData.u.phar.params->nistack = 4;
    FmtData.u.phar.params->istksize = 1;
    FmtData.u.phar.params->extender_flags = 0;
    FmtData.u.phar.params->unpriv = 0;
    ChkBase(memorySubsystem, messagingSubsystem, 4 * 1024);
}

void FreePharFmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem)
{
    memorySubsystem->FreeMemory(FmtData.u.phar.breaksym);
    memorySubsystem->FreeMemory(FmtData.u.phar.params);
    memorySubsystem->FreeMemory(FmtData.u.phar.stub);
}
