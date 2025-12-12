#include "pch.h"
#include "globals.h"
#include "hash.h"

pHTable CreateHTable(int size, pHashFunc hashFunc, pHashElemCmp compareFunc, pAllocFunc allocFunc, pFreeFunc freeFunc)
{
    pHTable table;

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

    return table;
}

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

void ZapHTable(pHTable table, void (*zapElemAction)(void*)) {
    int i;
    pHTElem* tblPtr;
    pHTElem tblElem, temp;
    pFreeFunc free;

    if (table == nullptr) {
        return;
    }

    tblPtr = table->tbl;
    free = table->freeFunc;

    for (i = 0; i < table->size; i++) {
        for (tblElem = tblPtr[i]; tblElem != nullptr; tblElem = temp) {
            if (zapElemAction != nullptr) {
                zapElemAction(tblElem->userData);
            }
            temp = tblElem->next;
            free(tblElem);
        }
    }

    free(table->tbl);
    free(table);
}
