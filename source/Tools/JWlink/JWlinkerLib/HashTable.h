#pragma once

#include "MemorySubsystem.h"

typedef void* AllocFunc(size_t size);
typedef AllocFunc* pAllocFunc;
typedef void FreeFunc(void* elem);
typedef FreeFunc* pFreeFunc;

typedef unsigned HashFunc(void* elem, unsigned size);
typedef HashFunc* pHashFunc;

typedef int HashElemCmp(const void* elem1, const void* elem2);
typedef HashElemCmp* pHashElemCmp;

typedef struct _HTElem
{
    void* userData;
    struct _HTElem* next;
} *pHTElem;

typedef struct _TAG_HTable
{
    pHTElem* tbl;
    unsigned size;
    int allowDoubles;
    pHashFunc hashFunc;
    pHashElemCmp compareFunc;       
    pAllocFunc allocFunc;
    pFreeFunc freeFunc;

    struct
    {
        long numElems;
        int longestChainLen;
    } stats;
} *pHTable;

class HashTable
{
	MemorySubsystem* memorySubsystem;
    pHTable table;
public:
	HashTable(MemorySubsystem* memorySubsystem);
	~HashTable();
    void CreateHTable(int size, pHashFunc hashFunc, pHashElemCmp compareFunc, pAllocFunc allocFunc, pFreeFunc freeFunc);
    void ZapHTable(void (*zapElemAction)(void*));
};

