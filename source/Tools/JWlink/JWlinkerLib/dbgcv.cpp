#include "pch.h"
#include "dbgcv.h"
#include "globals.h"
#include "Structs.h"
#include "MemorySubsystem.h"
#include "debug.h"

using namespace std;

#pragma pack( 1 )

typedef struct
{
    uint32_t start;
    uint32_t end;
} offset_range;

typedef struct
{
    uint16_t         cFile;
    uint16_t         cSeg;
    uint32_t         baseSrcFile[1];
    offset_range        range[1];
    uint16_t         seg[1];
    uint16_t         pad;
} cheesy_module_header;

typedef struct
{
    uint16_t         cSeg;
    uint16_t         pad;
    uint32_t         baseSrcLn[1];
    offset_range        range[1];
    uint8_t          name[1];           
} cheesy_file_table;

typedef struct
{
    uint16_t         Seg;
    uint16_t         cPair;
} cheesy_mapping_table;

#pragma pack()

typedef struct
{
    virt_mem            linestart;
    virt_mem            offbase;
    virt_mem            numbase;
    offset_range        range;
    uint32_t         prevaddr;
    uint16_t         seg;
    uint8_t          needsort : 1;
} cvlineinfo;

enum
{
    CVSECT_MODULE,
    CVSECT_MISC,
    CVSECT_MODDIR,
    CVSECT_DIRECTORY,
    NUM_CV_SECTS
};

virt_mem SectAddrs[NUM_CV_SECTS];
virt_mem         CVBase;
uint32_t             CVSize;        
uint32_t             CVDebugDirEntryPos = 0;
unsigned         TempIndex;
cvlineinfo       LineInfo;

void CVInit(void)
{
    DEBUG((DBG_OLD, "CVInit() enter"));
    memset(SectAddrs, 0, sizeof(virt_mem) * NUM_CV_SECTS);
    memset(&LineInfo, 0, sizeof(cvlineinfo));
    TempIndex = 0;
}