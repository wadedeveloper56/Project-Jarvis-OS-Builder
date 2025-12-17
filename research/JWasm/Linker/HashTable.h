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

typedef struct _HashTableElement {
	void* userData;
	_HashTableElement* next;
} HashTableElement, * HashTableElementPtr, ** HashTableElementPtrPtr;

typedef struct _HashTableData {
	HashTableElementPtrPtr tbl;
	unsigned size;
	int allowDoubles;
	pHashFunc hashFunc;
	pHashElemCmp compareFunc; // Take two elements of the table;
	// Return 0 iff elem1 == elem2
	//pAllocFunc allocFunc;
	//pFreeFunc freeFunc;
	struct {
		long numElems;
		int longestChainLen;
	} stats;
} HashTableData, * HashTableDataPtr;

class HashTable
{
	MemorySubsystem* memory;
public:
	HashTable(MemorySubsystem* memory);
	~HashTable();
	/*
	createHTable -- Create hash table
	size -- The size of a table, may be smaller than the number of elements that will be stored in it.
	keyFunc -- The key function which returns a key for an element.  The value returned by calling this function must be within [0, size-1]
	compareFunc -- Take 2 elements and return 0 iff elem1 == elem2.
	EXAMPLE:   table = CreateHTable(128,  StringHashFunc, strcmp, malloc, free);
   */
	HashTableDataPtr CreateHTable(int size, pHashFunc hashFunc, pHashElemCmp compareFunc);

	/* CreateHTableDouble: Same as CreateHTable, except allow to have  double entries. */
	HashTableDataPtr CreateHTableDouble(int size, pHashFunc hashFunc, pHashElemCmp compareFunc);

	/* addHTableElem  -- Add element to a hash table, return element added.
	   If table was created using CreateHTable, and elem already exists in
	   the table, it will not be added. If table was created by CreateHTableD,
	   it will be.
	   If error occurs, return NULL. Otherwise return 'elem'
	*/
	void* AddHTableElem(HashTableDataPtr table, void* elem);

	/*  FindHTableElem -- Find an element in hash table.
		Return NULL if the element is not found, otherwise return a pointer
		to that element.
	*/
	void* FindHTableElem(HashTableDataPtr table, void* elem);

	/*  WalkHTableElem -- Perform 'action' for every elememnt 'elem' in hash table.
		Return number of 'elem' in hash table.
	*/
	int WalkHTableElem(HashTableDataPtr table, void* elem, void (*action)(void*));

	/*  WalkHTable[Cookie] -- Perform 'action' for every single element in hash
		table. Use Cookie as an extra parameter to 'action'.
	*/
	void WalkHTableCookie(HashTableDataPtr table, void (*action)(void*, void*), void* cookie);
	void WalkHTable(HashTableDataPtr table, void (*action)(void*));

	/*  RehashHTable -- rehash the table. Useful if the entries of the table
		have changed. Important: If during changes to elements of hash table
		some duplicates were created, this function will not get rid of them.
	*/
	void RehashHTable(HashTableDataPtr table);

	/*  ZapHTable -- Deallocate all of the elements of table using zapElemAction,
		then remove the table from memory.  zapElemAction may be NULL, in
		which case it is not called.
	*/
	void ZapHTable(HashTableDataPtr table, void (*zapElemAction)(void*));

	/*  GetHTableStats -- Get statistics about the hash table.  Useful for
		evaluating performance of a hash table to determine if a larger
		size table or better hashing function is needed
	*/
	void GetHTableStats(HashTableDataPtr table, int* numElem, int* longestChainLen);
	long GetHTableNumOfElems(HashTableDataPtr table);

	/* Collect distribution of a table */
	void CollectHTableDistribution(HashTableDataPtr table, unsigned* stat);
};

/*  StringHashFunc -- Hash function for null-terminated strings.
	IMPORTANT: This function assumes that 'size' parameter is a power of 2
	(for example, 64, 128, but NOT 100)
*/
unsigned StringHashFunc(char* s, unsigned size);

/*  StringiHashFunc -- Hash function for null-terminated strings.
	The same as StringHashFunc, but ignore the case. Size must be a power of 2.
*/
unsigned StringiHashFunc(void* s, unsigned size);

/* Hash a pointer. Size must be a power of 2. */
unsigned PtrHashFunc(void* p, unsigned size);

/* General purpose hash of n bytes of data. Size must be a power of 2. */
unsigned DataHashFunc(void* data, unsigned n, unsigned size);


