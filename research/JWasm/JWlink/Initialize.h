#pragma once

#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"

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

void ResetPermData(MemorySubsystem* memory);
void CleanPermData(MessagingSubsystem* msg, MemorySubsystem* memory, FileSubsystem* file);
void LnkMemInit(void);
void LnkMemFini(void);
void InitCmdFile(void);
void LnkFilesInit(void);
int InitMsg(void);
int FiniMsg(void);
void InitNodes(MemorySubsystem* memory);
void BurnNodes(MemorySubsystem* memory);
void FiniLinkStruct(MemorySubsystem* memory);
void InitTokBuff(MemorySubsystem* memory);
void FreeTokBuffs(MemorySubsystem* memory);
void InitSpillFile(void);
void InitSym(MemorySubsystem* memory);
void FiniSym(MemorySubsystem* memory);
void CacheFini(void);
void InitObjORL(MemorySubsystem* memory);
void ObjORLFini(void);
void* CachePermRead(file_list* list, unsigned long pos, unsigned len);
void* CacheRead(file_list* list, unsigned long pos, unsigned len);
void FreeOutFiles(FileSubsystem* file, MemorySubsystem* memory);
void ResetMisc(void);
section* NewSection(MemorySubsystem* memory);
void ResetDBI(void);
void ResetMapIO(void);
void ResetCmdAll(void);
void ResetOvlSupp(void);
void ResetComdef(void);
void ResetDistrib(void);
void BurnSystemList(MemorySubsystem* memory);
void FreeList(MemorySubsystem* memory, void* _curr);
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
void CloseSpillFile(FileSubsystem* file, MemorySubsystem* memory);
void CleanTraces(MemorySubsystem* memory);
void FreePaths(MemorySubsystem* memory);
void FreeUndefs(MemorySubsystem* memory);
void FreeLocalImports(void);
void CleanLoadFile(void);
void CleanLinkStruct(MessagingSubsystem* msg, FileSubsystem* file, MemorySubsystem* memory);
void FreeFiles(FileSubsystem* file, MemorySubsystem* memory, file_list* list);
void FreeSections(MessagingSubsystem* msg, FileSubsystem* file, MemorySubsystem* memory, section* sec);
void FreeGroups(MessagingSubsystem* msg, group_entry* head);
void FreeFormatStuff(void);
void FreeObjInfo(void);
void FreeVirtMem(MemorySubsystem* memory);
void CleanToc(MemorySubsystem* memory);
void CleanSym(MessagingSubsystem* msg, MemorySubsystem* memory);
void CacheFree(MemorySubsystem* memory, file_list* list, void* mem);
void CacheClose(FileSubsystem* files, MemorySubsystem* memory, file_list* list, unsigned pass);
void FreeObjCache(MemorySubsystem* memory, file_list* list);

