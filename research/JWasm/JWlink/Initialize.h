#pragma once

#include "MemorySubsystem.h"

#define NODE_ARRAY_SIZE 256
#define MAX_NUM_NODES   128
#define NEED_NEW_ARRAY( x ) (!((x) & 0xFF))
#define ARRAY_NUM( x )      ((x) >> 8 )
#define ELEMENT_NUM( x )    ((x) & 0xFF)
#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE

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

void ResetPermData(void);
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

