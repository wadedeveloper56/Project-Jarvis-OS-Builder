#include "pch.h"
#include "MemorySubsystem.h"
#include "objfree.h"
#include "ObjectNode.h"

using namespace std;

void FiniLinkStruct(shared_ptr<MemorySubsystem> memorySubsystem)
{
    BurnNodes(memorySubsystem);
    //FreeTokBuffs();
    //CacheFini();
    //ObjORLFini();
}