#include "pch.h"
#include "hash.h"

void ZapHTable(pHTable table, void (*zapElemAction)(void*)) {
    int i;
    pHTElem* tblPtr;
    pHTElem tblElem, temp;
    pFreeFunc free;

    if (table == NULL) {
        return;
    }

    tblPtr = table->tbl;
    free = table->freeFunc;

    for (i = 0; i < table->size; i++) {
        for (tblElem = tblPtr[i]; tblElem != NULL; tblElem = temp) {
            if (zapElemAction != NULL) {
                zapElemAction(tblElem->userData);
            }
            temp = tblElem->next;
            free(tblElem);
        }
    }

    free(table->tbl);
    free(table);
}
