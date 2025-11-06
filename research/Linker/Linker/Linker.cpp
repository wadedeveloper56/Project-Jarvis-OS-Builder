#include "pch.h"
#include "globals.h"

static nodearray* MakeArray(unsigned size)
{
    nodearray* nodes = new nodearray;
    nodes->num = 0;
    nodes->elsize = size;
    nodes->arraymax = 0;
    size *= NODE_ARRAY_SIZE;
    nodes->array[0] = new char[size];
    memset(nodes->array[0], 0, size);
    return(nodes);
}

void InitSubSystems()
{
    GrpNodes = MakeArray(sizeof(grpnode));
    SegNodes = MakeArray(sizeof(segnode));
    ExtNodes = MakeArray(sizeof(extnode));
    NameNodes = MakeArray(sizeof(list_of_names*));
    TokSize = MAX_HEADROOM;
    TokBuff = new char[MAX_HEADROOM];
    TempFile = NULL;
    TFileName = NULL;
    TmpFSize = 0;
    GlobalSymPtrs = new symbol * [GLOBAL_TABALLOC];
    StaticSymPtrs = new symbol * [STATIC_TABALLOC];
    //ORLHandle = ORLInit(&ORLFuncs);
    ReadCacheList = NULL;
}

void LinkMainLine(char* cmds)
{
}

void FiniSubSystems()
{
}

int main()
{
    InitSubSystems();
    LinkMainLine(NULL);
    FiniSubSystems();
    return((LinkState & LINK_ERROR) ? 1 : 0);
}

