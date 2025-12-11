#include "pch.h"
#include "globals.h"
#include "mem.h"
#include "ntio.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "objnode.h"
#include "objio.h"
#include "spillio.h"
#include "lsymtab.h"
#include "objorl.h"
#include "cmdline.h"
#include "objfree.h"
#include "permdata.h"
#include "virtpage.h"
#include "dbgall.h"
#include "mapio.h"
#include "cmdall.h"
#include "ovlsupp.h"
#include "wcomdef.h"
#include "distrib.h"
#include "loadnov.h"
#include "loadpe.h"
#include "obj2supp.h"
#include "objomf.h"
#include "objpass1.h"
#include "objstrip.h"
#include "omfreloc.h"
#include "reloc.h"
#include "symtrace.h"
#include "loadfile.h"
#include "salloc.h"
#include "toc.h"
#include "libr.h"
#include "procfile.h"

static char* ArgSave;
char** _argv;
int  _argc;

void InitSubSystems(void)
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

void FiniSubSystems(void)
{
    FiniLinkStruct();
    FiniMsg();
    FiniSym();
    LnkMemFini();
}

static void ResetMisc(void)
{
    ///* jwlink: default is: multiple defines are NOT ok */
    //LinkFlags = REDEFS_OK | CASE_FLAG | FAR_CALLS_FLAG;
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
    // set case sensitivity for symbols
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
    ResetMapIO();
    ResetCmdAll();
    ResetOvlSupp();
    ResetComdef();
    ResetDistrib();
    ResetLoadNov();
    ResetLoadPE();
    ResetObj2Supp();
    ResetObjIO();
    ResetObjOMF();
    ResetObjPass1();
    ResetObjStrip();
    ResetOMFReloc();
    ResetReloc();
    ResetSymTrace();
    ResetLoadFile();
    ResetAddr();
    ResetToc();
}

static void CleanSubSystems(void)
{
    if (MapFile != NIL_HANDLE) {
        QClose(MapFile, MapFName);
        MapFile = NIL_HANDLE;
    }
    FreeOutFiles();
    _LnkFree(MapFName);
    BurnSystemList();
    FreeList(LibPath);
    CloseSpillFile();
    CleanTraces();
    FreePaths();
    FreeUndefs();
    FreeLocalImports();
    CleanLoadFile();
    CleanLinkStruct();
    FreeFormatStuff();
    FreeObjInfo();
    //FreeVirtMem();
    //CleanToc();
    //CleanSym();
    CleanPermData();
}

static void DoLink(char* cmdline)
{
//#ifndef __OSI__
//    signal(SIGINT, &TrapBreak); /* so we can clean up */
//#endif
//    StartTime();
//    DoCmdFile(cmdline);
//    CheckErr();
//    MapInit();
//    SetupFakeModule();
//    ProcObjFiles(); /* ObjPass1 */
//    CheckErr();
//    DoDefaultSystem();
//    if (LinkState & LIBRARIES_ADDED) {
//        FindLibPaths();
//        LinkState |= SEARCHING_LIBRARIES;
//        ResolveUndefined();
//        LinkState &= ~SEARCHING_LIBRARIES;
//        LinkState |= GENERATE_LIB_LIST;
//    }
//    ProcLocalImports();
//    DecideFormat();
//    SetFormat();
//    ConvertLazyRefs();
//    SetSegments();
//    CheckErr();
//    DefBSSSyms();
//    LinkFakeModule();
//    PreAddrCalcFormatSpec();
//    ReportUndefined();
//    CheckClassOrder();
//    CalcSegSizes();
//    SetStkSize();
//    AutoGroup();
//    CalcAddresses();
//    GetBSSSize();
//    GetStkAddr();
//    GetStartAddr();
//    PostAddrCalcFormatSpec();
//    CheckErr();
//    InitLoadFile();
//    ObjPass2();
//    CheckErr();
//    FiniLoadFile();
//    WritePermData();
//    BuildImpLib();
//    EndTime();
//#ifndef __OSI__
//    signal(SIGINT, SIG_IGN); /* we're going to clean up anyway */
//#endif
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
    //    Spawn(&LinkMeBaby);
        CleanSubSystems();
    //    cmds = GetNextLink();
        if (cmds == NULL) break;
    }
}

int main(int argc, char** argv)
{
    InitSubSystems();
    LinkMainLine(NULL);
    FiniSubSystems();
    return((LinkState & LINK_ERROR) ? 1 : 0);
}
