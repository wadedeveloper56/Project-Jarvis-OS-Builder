#pragma once

#include "cache.h"

#define NODE_ARRAY_SIZE 256
#define MAX_NUM_NODES   128
#define NEED_NEW_ARRAY( x ) (!((x) & 0xFF))
#define ARRAY_NUM( x )      ((x) >> 8 )
#define ELEMENT_NUM( x )    ((x) & 0xFF)
#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE
#define BUFF_BLOCK_SIZE (16*1024)
#define CACHE_PAGE_SIZE         (8*1024)
enum {
    MAX_REC = 1024,
    UNDEFINED = 0xffff,   /* undefined segment */
};

typedef struct nodearray {
    unsigned    num;            // number of nodes inserted
    unsigned    elsize;         // size of individual element in array.
    unsigned    arraymax;       // the number of node arrays allocated - 1
    char* array[MAX_NUM_NODES];   // the array.
} nodearray; 

extern nodearray* ExtNodes;           // ptr to obj file import list
extern nodearray* SegNodes;           // ptr to obj file segment list
extern nodearray* GrpNodes;           // ptr to obj file group list
extern nodearray* NameNodes;          // ptr to obj file lname list

void ResetPermData();
void CleanPermData();
void LnkMemInit(void);
void LnkMemFini(void);
void InitCmdFile(void);
void LnkFilesInit(void);
int InitMsg(void);
int FiniMsg(void);
void InitNodes();
void BurnNodes();
void FiniLinkStruct();
void InitTokBuff();
void FreeTokBuffs();
void InitSpillFile(void);
void InitSym();
void FiniSym();
void InitObjORL();
void ObjORLFini(void);
void FreeOutFiles();
void ResetMisc(void);
section* NewSection();
void ResetDBI(void);
void ResetMapIO(void);
void ResetCmdAll(void);
void ResetOvlSupp(void);
void ResetComdef(void);
void ResetDistrib(void);
void BurnSystemList();
void FreeList(void* _curr);
void ResetLoadNov(void);
void ResetLoadPE(void);
void ResetObj2Supp(void);
void ResetObjIO(void);
void ResetObjOMF(void);
void ResetObjPass1(void);
void ResetObjStrip(void);
void ResetOMFReloc(void);
void ResetReloc(void);
void ResetSymTrace(void);
void ResetLoadFile(void);
void ResetAddr(void);
void ResetToc(void);
void CloseSpillFile();
void CleanTraces();
void FreePaths();
void FreeUndefs();
void FreeLocalImports(void);
void CleanLoadFile(void);
void CleanLinkStruct();
void FreeFiles(file_list* list);
void FreeSections(section* sec);
void FreeGroups(group_entry* head);
void FreeFormatStuff();
void FreeObjInfo(void);
void FreeVirtMem();
void CleanToc();
void CleanSym();
void FreeObjCache(file_list* list);
void FreeSegFlags(seg_flags* curr);
bool DumpFileCache(infilelist* file, bool nuke);