#include "pch.h"
#include "hash.h"

unsigned StringiHashFunc(void* _s, unsigned size) 
{
	char* s = (char*)_s;
	enum { b = 101 };
	unsigned long key = 0;
	int i;

	for (i = 0; s[i] != 0; i++)
	{
		key += toupper(s[i]);
		key *= b;
	}

	key = key & (size - 1);

	return key;
}

pHTable CreateHTable(int size, pHashFunc hashFunc, pHashElemCmp compareFunc, MemorySubsystem *memorySubsystem)
{
	pHTable table;

	table = (pHTable)memorySubsystem->AllocateMemory(sizeof * table);
	table->tbl = (pHTElem*)memorySubsystem->AllocateMemory(sizeof table[0] * size);
	memset(table->tbl, 0, sizeof table[0] * size);

	table->size = size;
	table->hashFunc = hashFunc;
	table->compareFunc = compareFunc;
	table->memorySubsystem = memorySubsystem;
	table->stats.numElems = 0;
	table->stats.longestChainLen = 0;
	table->allowDoubles = 0;

	return table;
}

void ZapHTable(pHTable table) 
{
	int i;
	pHTElem* tblPtr;
	pHTElem tblElem, temp;

	if (table == NULL)
	{
		return;
	}

	tblPtr = table->tbl;

	for (i = 0; i < table->size; i++)
	{
		for (tblElem = tblPtr[i]; tblElem != NULL; tblElem = temp)
		{
			table->memorySubsystem->FreeMemory(tblElem->userData);
			temp = tblElem->next;
			table->memorySubsystem->FreeMemory(tblElem);
		}
	}
	table->memorySubsystem->FreeMemory(table->tbl);
	table->memorySubsystem->FreeMemory(table);
}
