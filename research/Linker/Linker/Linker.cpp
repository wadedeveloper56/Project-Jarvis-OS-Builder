#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "command.h"
#include "fileio.h"
#include "objpass2.h"
#include "cmdline.h"
#include "loadfile.h"
#include "objfree.h"
#include "mapio.h"
#include "objcalc.h"
#include "procfile.h"
#include "spillio.h"
#include "virtmem.h"
#include "loados2.h"
#include "loadpe.h"
#include "loadqnx.h"
#include "loadnov.h"
#include "loadelf.h"
#include "symtrace.h"
#include "objnode.h"
#include "objio.h"
#include "distrib.h"
#include "objorl.h"
#include "strtab.h"
#include "carve.h"
#include "permdata.h"
#include "toc.h"
#include "dbgall.h"
#include "objpass1.h"
#include "obj2supp.h"
#include "cmdall.h"
#include "reloc.h"
#include "salloc.h"
#include "objstrip.h"
#include "symtab.h"
#include "omfreloc.h"
#include "overlays.h"
#include "wcomdef.h"
#include "objomf.h"
#include "wlink.h"
#include "library.h"
#include "globals.h"

int _argc;
char** _argv;
static char* ArgSave;

void InitSubSystems()
{
    LnkMemInit();
    LnkFilesInit();
    InitMsg();
    InitNodes();
    InitTokBuff();
    InitSpillFile();
    InitSym();
    InitObjORL();
    InitCmdFile();
}

static void ResetMisc(void)
{
    LinkFlags = CASE_FLAG | FAR_CALLS_FLAG;
    LinkState = MAKE_RELOCS;
    AbsGroups = NULL;
    DataGroup = NULL;
    IDataGroup = NULL;
    MapFile = NIL_HANDLE;
    MapFName = NULL;
    OutFiles = NULL;
    ObjLibFiles = NULL;
    LibModules = NULL;
    Groups = NULL;
    CurrLoc.seg = UNDEFINED;
    CurrLoc.off = 0;
    OvlClasses = NULL;
    OvlVectors = NULL;
    VecNum = 0;
    OvlNum = 0;
    OvlFName = NULL;
    CurrMod = NULL;
    StackSize = 0x1000;
    ResetSym();
    SetSymCase();
    SetLibCase();
}

static void ResetSubSystems(void)
{
    ResetPermData();
    ResetMsg();
    VirtMemInit();
    ResetMisc();
    Root = NewSection();
    ResetDBI();
    //ResetMapIO();
    //ResetCmdAll();
    //ResetOvlSupp();
    //ResetComdef();
    //ResetDistrib();
    //ResetLoadNov();
    //ResetLoadPE();
    //ResetObj2Supp();
    //ResetObjIO();
    //ResetObjOMF();
    //ResetObjPass1();
    //ResetObjStrip();
    //ResetOMFReloc();
    //ResetReloc();
    //ResetSymTrace();
    //ResetLoadFile();
    //ResetAddr();
    //ResetToc();
}

static void CleanSubSystems(void)
{
    //if (MapFile != NIL_HANDLE) {
    //    QClose(MapFile, MapFName);
    //    MapFile = NIL_HANDLE;
    //}
    //FreeOutFiles();
    //_LnkFree(MapFName);
    //BurnSystemList();
    //FreeList(LibPath);
    //CloseSpillFile();
    //CleanTraces();
    //FreePaths();
    //FreeUndefs();
    //FreeLocalImports();
    //CleanLoadFile();
    //CleanLinkStruct();
    //FreeFormatStuff();
    //FreeObjInfo();
    //FreeVirtMem();
    //CleanToc();
    //CleanSym();
    //CleanPermData();
}

static void DoLink(char* cmdline)
{
    //NOT YET
}

static void LinkMeBaby(void)
{
    ResetSubSystems();
    DoLink(ArgSave);
}

void LinkMainLine(char* cmds)
{
    for (;;) {
        ArgSave = cmds;                
        Spawn(&LinkMeBaby);
        CleanSubSystems();
        cmds = GetNextLink();
        if (cmds == NULL) break;
    }
}

void FiniSubSystems()
{
    FiniLinkStruct();
    FiniMsg();
    FiniSym();
    LnkMemFini();
}

int main(int argc, char** argv)
{
    _argv = argv;
    _argc = argc;
    InitSubSystems();
    LinkMainLine(NULL);
    FiniSubSystems();
    return((LinkState & LINK_ERROR) ? 1 : 0);
}

