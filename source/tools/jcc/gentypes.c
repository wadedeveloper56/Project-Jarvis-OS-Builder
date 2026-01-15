#include "wic.h"

void forAllInSLList(pSLList pList, void (func)(void**))
{
    _SLList* temp;
    if (func == NULL) {
        return;
    }
    temp = pList->head;
    while (temp != pList->tail) {
        func(&(temp->userData));
        temp = temp->next;
    }
}

void addSLListElem(pSLList pList, void* elem)
{
    pList->tail->next = AllocateMemory(sizeof(_SLList));
    pList->tail->userData = elem;
    pList->tail = pList->tail->next;
}

int isEmptySLList(pSLList pList)
{
    return (pList->head == pList->tail);
}

void rewindCurrSLListPos(pSLList pList)
{
    pList->currPos = pList->head;
}

/* Allocate space for list AND initialize it */
pSLList createSLList(void) 
{
    pSLList newList = AllocateMemory(sizeof * newList);
    newList->head = AllocateMemory(sizeof * newList->head);
    newList->tail = newList->head;
    rewindCurrSLListPos(newList);
    return newList;
}

void zapSLList(pSLList pList, void (zapElem)(void*)) 
{
    _SLList* temp;
    if (pList == NULL) {
        return;
    }

    while (!isEmptySLList(pList)) {
        temp = pList->head;
        pList->head = pList->head->next;
        if (zapElem != NULL) {
            zapElem(temp->userData); temp->userData = NULL;
        }
        FreeMemory(temp); temp = NULL;
    }
    FreeMemory(pList->head); pList->head = NULL;
    FreeMemory(pList);
}
