#include "pch.h"
#include "globals.h"
#include "mem.h"

static char* ArgSave;
char** _argv;
int  _argc;

static void LinkMeBaby(void)
{
    //ResetSubSystems();
    //DoLink(ArgSave);
}

void LinkMainLine(char* cmds)
{
    //for (;;) {
    //    ArgSave = cmds;
    //    Spawn(&LinkMeBaby);
    //    CleanSubSystems();
    //    cmds = GetNextLink();
    //    if (cmds == NULL) break;
    //}
}

void InitSubSystems(void)
{
   LnkMemInit();
   // LnkFilesInit();
   // InitMsg();
   // InitNodes();
   // InitTokBuff();
   // InitSpillFile();
   // InitSym();
   // InitObjORL();
   // InitCmdFile();
}

void FiniSubSystems(void)
{
    //FiniLinkStruct();
    //FiniMsg();
    //FiniSym();
    LnkMemFini();
}

static void ResetSubSystems(void)
{
    //ResetPermData();
    //ResetMsg();
    //VirtMemInit();
    //ResetMisc();
    //Root = NewSection();
    //ResetDBI();
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

static void PreAddrCalcFormatSpec(void)
{
//#ifdef _OS2
//    if (FmtData.type & MK_PE) {
//        ChkPEData();
//    }
//    else if (FmtData.type & (MK_OS2 | MK_WIN_VXD)) {
//        if (IS_PPC_OS2) {
//            // Development temporarly on hold:
//            // ChkOS2ElfData();
//        }
//        else {
//            ChkOS2Data();
//        }
//    }
//#endif
//#ifdef _NOVELL
//    if (FmtData.type & MK_NOVELL) {
//        FindExportedSyms();
//    }
//#endif
//#ifdef _PHARLAP
//    if (FmtData.type & MK_PHAR_FLAT && LinkState & HAVE_16BIT_CODE
//        && !(CmdFlags & CF_HAVE_REALBREAK)) {
//        LnkMsg(WRN + MSG_NO_REALBREAK_WITH_16BIT, NULL);
//    }
//#endif
}

static void PostAddrCalcFormatSpec(void)
{
//#ifdef _OS2
//    if (FmtData.type & MK_PE) {
//        AllocPETransferTable();
//    }
//    else if (FmtData.type & MK_ELF) {
//        ChkElfData();
//    }
//    else if (FmtData.type & (MK_OS2 | MK_WIN_VXD)) {
//        if (IS_PPC_OS2) {
//            // Development temporarly on hold:
//            //PrepareOS2Elf();
//        }
//        else {
//            ChkOS2Exports();
//        }
//    }
//#endif
//#ifdef _QNXLOAD
//    else if (FmtData.type & MK_QNX) {
//        SetQNXSegFlags();
//    }
//#endif
}

static void ResetMisc(void)
{
    ///* jwlink: default is: multiple defines are NOT ok */
    ////LinkFlags = REDEFS_OK | CASE_FLAG | FAR_CALLS_FLAG;
    //LinkFlags = CASE_FLAG | FAR_CALLS_FLAG;
    //LinkState = MAKE_RELOCS;
    //AbsGroups = NULL;
    //DataGroup = NULL;
    //IDataGroup = NULL;
    //MapFile = NIL_HANDLE;
    //MapFName = NULL;
    //OutFiles = NULL;
    //ObjLibFiles = NULL;
    //LibModules = NULL;
    //Groups = NULL;
    //CurrLoc.seg = UNDEFINED;
    //CurrLoc.off = 0;
    //OvlClasses = NULL;
    //OvlVectors = NULL;
    //VecNum = 0;
    //OvlNum = 0;
    //OvlFName = NULL;
    //CurrMod = NULL;
    //StackSize = 0x1000;
    //// set case sensitivity for symbols
    //ResetSym();
    //SetSymCase();
    //SetLibCase();
}

static void DoDefaultSystem(void)
{
    //if (!(LinkState & FMT_DECIDED)) {
    //    if (LinkState & FMT_SEEN_32_BIT) {
    //        HintFormat(MK_386);
    //    }
    //    else if (LinkState & FMT_SEEN_64_BIT) {
    //        HintFormat(MK_PE);
    //    }
    //    else {
    //        HintFormat(MK_286 | MK_QNX);
    //    }
    //    if (!(LinkState & FMT_DECIDED)) {
    //        if (LinkState & FMT_SPECIFIED) {
    //            LnkMsg(FTL + MSG_AMBIG_FORMAT, NULL);
    //        }
    //        if (LinkState & FMT_SEEN_32_BIT) {
    //            ExecSystem("386");
    //        }
    //        else {
    //            ExecSystem("286"); /* no 386 obj's after this */
    //        }
    //    }
    //}
}

static void FindLibPaths(void)
{
    //AddFmtLibPaths();
    //if (LinkState & FMT_SEEN_32_BIT) {
    //    AddEnvPaths("LIB386");
    //}
    //else {
    //    AddEnvPaths("LIB286");
    //    /*
    //        If we haven't seen a 386 object file by this time, we're
    //        not going to.
    //    */
    //    HintFormat(MK_286);
    //}
    //AddEnvPaths("LIB");
}

int main(int argc, char** argv)
{
    InitSubSystems();
    LinkMainLine(NULL);
    FiniSubSystems();
    return((LinkState & LINK_ERROR) ? 1 : 0);
}
