#include "pch.h"
#include "globals.h"
#include "Initialize.h"

#ifdef _INT_DEBUG
static  int     Chunks;
#endif
static int      OpenFiles;      // the number of open files
static unsigned LastResult;
static bool     CaughtBreak;    // set to TRUE if break hit.
static char* TFileName;
static unsigned long    TmpFSize;
bool BannerPrinted;
nodearray* ExtNodes;           // ptr to obj file import list
nodearray* SegNodes;           // ptr to obj file segment list
nodearray* GrpNodes;           // ptr to obj file group list
nodearray* NameNodes;          // ptr to obj file lname list
symbol** GlobalSymPtrs;
symbol** StaticSymPtrs;

void LnkMemInit(void)
{
#ifdef _INT_DEBUG
    Chunks = 0;
#endif
}

void LnkFilesInit(void)
{
    OpenFiles = 0;
    CaughtBreak = false;
    _setmode(_fileno(stdin), O_BINARY);
    _setmode(_fileno(stdout), O_BINARY);
}

int InitMsg(void)
{
    BannerPrinted = false;
    return(EXIT_SUCCESS);
}

static nodearray* MakeArray(MemorySubsystem* memory,unsigned size)
{
    _ChkAlloc2(nodearray * ,nodes, sizeof(nodearray));
    nodes->num = 0;
    nodes->elsize = size;
    nodes->arraymax = 0;
    size *= NODE_ARRAY_SIZE;
    _ChkAlloc(char*, nodes->array[0], size);
    memset(nodes->array[0], 0, size);
    return(nodes);
}

void InitNodes(MemorySubsystem* memory)
{
    GrpNodes = MakeArray(memory, sizeof(grpnode));
    SegNodes = MakeArray(memory, sizeof(segnode));
    ExtNodes = MakeArray(memory, sizeof(extnode));
    NameNodes = MakeArray(memory, sizeof(list_of_names*));
}

static void BurnNodeArray(MemorySubsystem* memory, nodearray* list)
{
    for (int index = 0; index <= list->arraymax; index++) {
        _LnkFree(list->array[index]);
    }
    _LnkFree(list);
}

void BurnNodes(MemorySubsystem* memory)
{
    BurnNodeArray(memory, GrpNodes);
    BurnNodeArray(memory, SegNodes);
    BurnNodeArray(memory, ExtNodes);
    BurnNodeArray(memory, NameNodes);
}

void InitTokBuff(MemorySubsystem* memory)
{
    TokSize = MAX_HEADROOM;
    _ChkAlloc(char*, TokBuff, MAX_HEADROOM);
}

void FreeTokBuffs(MemorySubsystem* memory)
{
    if (TokBuff != NULL) {
        _LnkFree(TokBuff);
        TokBuff = NULL;
    }
}

void InitSpillFile(void)
{
    TempFile = NIL_HANDLE;
    TFileName = NULL;
    TmpFSize = 0;
    //SetBreak();
}

void InitSym(MemorySubsystem* memory)
{
    _ChkAlloc(symbol**, GlobalSymPtrs, GLOBAL_TABALLOC);
    _ChkAlloc(symbol**, StaticSymPtrs, STATIC_TABALLOC);
}

void FiniSym(MemorySubsystem* memory)
{
    _LnkFree(GlobalSymPtrs);
    _LnkFree(StaticSymPtrs);
}

void CacheFini(void)
{
}

void FiniLinkStruct(MemorySubsystem* memory)
{
    BurnNodes(memory);
    FreeTokBuffs(memory);
    CacheFini();
    //ObjORLFini();
}

int FiniMsg(void)
{
    return(EXIT_SUCCESS);
}
