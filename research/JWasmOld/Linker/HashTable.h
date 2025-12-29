#pragma once

#include "MemorySubsystem.h"

typedef void* AllocFunc(size_t size);
typedef AllocFunc* pAllocFunc;
typedef void FreeFunc(void* elem);
typedef FreeFunc* pFreeFunc;

typedef unsigned HashFunc(void* elem, unsigned size);
typedef HashFunc* pHashFunc;

// Return 0 iff elem1 == elem2
typedef int HashElemCmp(const void* elem1, const void* elem2);
typedef HashElemCmp* pHashElemCmp;

typedef struct _HTElem {
	void* userData;
	//_HTElem* next;
}  HashTableElemData, * HashTableElemDataPtr, ** HashTableElemenDataPtrPtr;

typedef struct _HTable {
	HashTableElemenDataPtrPtr tbl;
	unsigned size;
	bool allowDoubles;
	pHashFunc hashFunc;
	pHashElemCmp compareFunc; // Take two elements of the table;
	// Return 0 iff elem1 == elem2
	//pAllocFunc allocFunc;
	//pFreeFunc freeFunc;
	struct {
		long numElems;
		int longestChainLen;
	} stats;
} HashTableData, * HashTableDataPtr, ** HashTableDataPtrPtr;

class HashTable
{
	MemorySubsystem* memory;
public:
	HashTable(MemorySubsystem* memory);
	~HashTable();
	HashTableDataPtr CreateHTable(int size, pHashFunc hashFunc, pHashElemCmp compareFunc);
	HashTableDataPtr CreateHTableDouble(int size, pHashFunc hashFunc, pHashElemCmp compareFunc);
	void ZapHTable(HashTableDataPtr table);
};
unsigned StringHashFunc(char* s, unsigned size);
unsigned StringiHashFunc(void* s, unsigned size);
unsigned PtrHashFunc(void* p, unsigned size);
unsigned DataHashFunc(void* data, unsigned n, unsigned size);


