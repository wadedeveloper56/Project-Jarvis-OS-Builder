#include "pch.h"
#include "HashTable.h"

HashTable::HashTable(MemorySubsystem* memorySubsystem) : memorySubsystem(memorySubsystem), table(nullptr)
{
}

HashTable::~HashTable()
{
	ZapHTable(nullptr);
	table = nullptr;
}

void HashTable::CreateHTable(int size, pHashFunc hashFunc, pHashElemCmp compareFunc, pAllocFunc allocFunc, pFreeFunc freeFunc)
{
    table = (pHTable)allocFunc(sizeof * table);
    table->tbl = (pHTElem*)allocFunc(sizeof table[0] * size);
    memset(table->tbl, 0, sizeof table[0] * size);
    table->size = size;
    table->hashFunc = hashFunc;
    table->compareFunc = compareFunc;
    table->allocFunc = allocFunc;
    table->freeFunc = freeFunc;
    table->stats.numElems = 0;
    table->stats.longestChainLen = 0;
    table->allowDoubles = 0;
}

void HashTable::ZapHTable(void (*zapElemAction)(void*))
{
    int i;
    pHTElem* tblPtr;
    pHTElem tblElem, temp;
    pFreeFunc free;

    if (table == NULL)
    {
        return;
    }

    tblPtr = table->tbl;
    free = table->freeFunc;

    for (i = 0; i < table->size; i++)
    {
        for (tblElem = tblPtr[i]; tblElem != NULL; tblElem = temp)
        {
            if (zapElemAction != NULL)
            {
                zapElemAction(tblElem->userData);
            }
            temp = tblElem->next;
            free(tblElem);
        }
    }

    memorySubsystem->FreeMemory(table->tbl);
    memorySubsystem->FreeMemory(table);
}

