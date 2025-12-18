#include "pch.h"
#include "HashTable.h"

HashTable::HashTable(MemorySubsystem* memory)
{
	this->memory = memory;
}

HashTable::~HashTable()
{
}

HashTableDataPtr HashTable::CreateHTable(int size, pHashFunc hashFunc, pHashElemCmp compareFunc)
{
	pHTable table;

	table = (HashTableDataPtr)memory->AllocateMemory(sizeof * table);
	table->tbl = (pHTElem *)memory->AllocateMemory(sizeof table[0] * size);
	table->size = size;
	table->hashFunc = hashFunc;
	table->compareFunc = compareFunc;
	table->stats.numElems = 0;
	table->stats.longestChainLen = 0;
	table->allowDoubles = 0;
	return table;
}

HashTableDataPtr HashTable::CreateHTableDouble(int size, pHashFunc hashFunc, pHashElemCmp compareFunc)
{
	HashTableDataPtr table = CreateHTable(size, hashFunc, compareFunc);
	if (table != nullptr) {
		table->allowDoubles = 1;
	}
	return table;
}

//void* HashTable::AddHTableElem(HashTableDataPtr table, void* elem)
//{
//	unsigned key;
//	int chainLen = 0;
//	HashTableElementPtr tblElem;
//	pHashElemCmp cmp = table->compareFunc;
//	key = table->hashFunc(elem, table->size);
//	if (table->allowDoubles)
//	{
//		for (tblElem = (HashTableElementPtr)table->tbl[key]; tblElem != NULL; tblElem = tblElem->next)
//		{
//			chainLen++;
//		}
//	}
//	else {
//		for (tblElem = (HashTableElementPtr)table->tbl[key]; tblElem != NULL; tblElem = tblElem->next)
//		{
//			chainLen++;
//			if (!cmp(elem, tblElem->userData)) {
//				return tblElem->userData;
//			}
//		}
//	}
//
//	tblElem = (HashTableElementPtr)memory->AllocateMemory(sizeof(HashTableElement));
//	tblElem->userData = elem;
//	tblElem->next = table->tbl[key];
//	table->tbl[key] = tblElem;
//	chainLen++;
//	table->stats.numElems++;
//	if (chainLen > table->stats.longestChainLen) {
//		table->stats.longestChainLen = chainLen;
//	}
//	return elem;
//}
//
//void* HashTable::FindHTableElem(HashTableDataPtr table, void* elem) {
//	int key;
//	HashTableElementPtr tblElem;
//	pHashElemCmp cmp = table->compareFunc;
//	key = table->hashFunc(elem, table->size);
//	for (tblElem = table->tbl[key]; tblElem != NULL; tblElem = tblElem->next)
//	{
//		if (!cmp(elem, tblElem->userData)) {
//			return tblElem->userData;
//		}
//	}
//	return NULL;
//}
//
//int HashTable::WalkHTableElem(HashTableDataPtr table, void* elem, void (*action)(void*))
//{
//	HashTableElementPtr tblElem;
//	int numElem = 0;
//	int key = table->hashFunc(elem, table->size);
//	pHashElemCmp cmp = table->compareFunc;
//	for (tblElem = table->tbl[key]; tblElem != NULL; tblElem = tblElem->next) {
//		if (!cmp(elem, tblElem->userData)) {
//			action(tblElem->userData);
//			numElem++;
//		}
//	}
//	return numElem;
//}
//
//void HashTable::WalkHTableCookie(HashTableDataPtr table, void (*action)(void*, void*),void* cookie) 
//{
//	unsigned int i;
//	HashTableElementPtrPtr tblPtr = table->tbl;
//	HashTableElementPtr tblElem;
//
//	if (action == NULL) {
//		return;
//	}
//	for (i = 0; i < table->size; i++) {
//		for (tblElem = tblPtr[i]; tblElem != NULL; tblElem = tblElem->next) {
//			action(tblElem->userData, cookie);
//		}
//	}
//}
//
//void HashTable::WalkHTable(HashTableDataPtr table, void (*action)(void*))
//{
//	/* For speed, do not use WalkHTableCookie */
//	unsigned int i;
//	HashTableElementPtrPtr tblPtr = table->tbl;
//	HashTableElementPtr tblElem;
//
//	if (action == NULL) {
//		return;
//	}
//
//	for (i = 0; i < table->size; i++) {
//		for (tblElem = tblPtr[i]; tblElem != NULL; tblElem = tblElem->next) {
//			action(tblElem->userData);
//		}
//	}
//}
//
//void HashTable::RehashHTable(HashTableDataPtr table) {
//	unsigned int i;
//	HashTableElementPtrPtr tbl;
//	HashTableElementPtr elem;
//	HashTableElementPtrPtr pelem;
//	unsigned hash;
//
//	tbl = table->tbl;
//	for (i = 0; i < table->size; i++) {
//		for (pelem = &tbl[i]; *pelem != NULL; ) {
//			elem = *pelem;
//			hash = table->hashFunc(elem->userData, table->size);
//			if (i != hash) {
//				*pelem = elem->next;
//				elem->next = tbl[hash];
//				tbl[hash] = elem;
//			}
//			else {
//				if (*pelem == NULL) break;
//				pelem = &((*pelem)->next);
//			}
//		}
//	}
//}
//
//void HashTable::ZapHTable(HashTableDataPtr table, void (*zapElemAction)(void*)) {
//	unsigned int i;
//	HashTableElementPtrPtr tblPtr;
//	HashTableElementPtr tblElem;
//	HashTableElementPtr temp;
//
//	if (table == NULL) {
//		return;
//	}
//	tblPtr = table->tbl;
//	for (i = 0; i < table->size; i++) {
//		for (tblElem = tblPtr[i]; tblElem != NULL; tblElem = temp) {
//			if (zapElemAction != NULL) {
//				zapElemAction(tblElem->userData);
//			}
//			temp = tblElem->next;
//			memory->FreeMemory(tblElem);
//		}
//	}
//
//	memory->FreeMemory(table->tbl);
//	memory->FreeMemory(table);
//}
//
//void HashTable::GetHTableStats(HashTableDataPtr table, int* numElems, int* longestChainLen) {
//	*numElems = table->stats.numElems;
//	*longestChainLen = table->stats.longestChainLen;
//}
//
//long HashTable::GetHTableNumOfElems(HashTableDataPtr table) {
//	return table->stats.numElems;
//}

unsigned StringHashFunc(char* s, unsigned size) {
	enum { b = 101 };
	unsigned long key = 0;
	int i;

	for (i = 0; s[i] != 0; i++) {
		key += s[i];
		key *= b;
	}

	key = key & (size - 1);

	return key;
}

unsigned StringiHashFunc(void* _s, unsigned size) {
	char* s = (char*)_s;
	enum { b = 101 };
	unsigned long key = 0;
	int i;

	for (i = 0; s[i] != 0; i++) {
		key += toupper(s[i]);
		key *= b;
	}

	key = key & (size - 1);

	return key;
}

unsigned DataHashFunc(void* data, unsigned n, unsigned size) {
	enum { b = 101 };
	unsigned long key = 0;
	unsigned int i;

	for (i = 0; i < n; i++) {
		key += ((char*)data)[i];
		key *= b;
	}

	key = key & (size - 1);

	return key;
}

unsigned PtrHashFunc(void* p, unsigned size) 
{
	return DataHashFunc(&p, sizeof p, size);
}

//void HashTable::CollectHTableDistribution(HashTableDataPtr table, unsigned* stat) 
//{
//	unsigned int i, n;
//	HashTableElementPtrPtr tblPtr = table->tbl;
//	HashTableElementPtr tblElem;
//
//	for (i = 0; i < table->size; i++) {
//		n = 0;
//		for (tblElem = tblPtr[i]; tblElem != NULL; tblElem = tblElem->next) {
//			n++;
//		}
//		stat[i] = n;
//	}
//}
//
