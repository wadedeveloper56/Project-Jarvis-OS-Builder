#include "pch.h"
#include "hash.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "MemorySubsystem.h"

unsigned StringiHashFunc(void* _s, unsigned size) {
    char* s = (char *)_s;
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

pHTable CreateHTable(int size, pHashFunc hashFunc, pHashElemCmp compareFunc)
{
    pHTable table;

    table = (pHTable)memory->AllocateMemory(sizeof * table);
    table->tbl = (pHTElem *)memory->AllocateMemory(sizeof table[0] * size);
    memset(table->tbl, 0, sizeof table[0] * size);

    table->size = size;
    table->hashFunc = hashFunc;
    table->compareFunc = compareFunc;
    table->memory = memory;
    table->stats.numElems = 0;
    table->stats.longestChainLen = 0;
    table->allowDoubles = 0;

    return table;
}
