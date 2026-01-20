#pragma once

/* Generic singly linked linked list, Generic queue. */
typedef struct _SLList {
    struct _SLList* next;
    void *userData;
} _SLList;

typedef struct SLList {
    _SLList *head;  /* 1-st element in the list */
    _SLList *tail;  /* Last (most recently added) element in the list */
    _SLList *currPos;
} *pSLList;

/* Generic stack */
typedef pSLList pStack;

#define createStack  createSLList
#define pushStackElem(stack, elem)  addBegSLListElem(stack, elem)
#define popStackElem(stack, ppElem) unqueSLListElem(stack, ppElem)

typedef pStack pWicStack;

#define popWicStackElem  popStackElem

pSLList createSLList(void);
int isEmptySLList(pSLList pList);
pSLList dupSLList(pSLList pList, void* (*action)(void*));
void addSLListElem(pSLList pList, void* elem);
void addBegSLListElem(pSLList pList, void* elem);
void addBegSLListSLList(pSLList pList, pSLList listAdd, void* (*action)(void*));
pSLList combine2SLList(pSLList l1, pSLList l2);
void insertSLListAfterCurrPosElem(pSLList pList, void* elem);
void setCurrSLListPosElem(pSLList pList, void* elem);
int getCurrSLListPosElem(pSLList pList, void* _pElem);
void incCurrSLListPos(pSLList pList);
void rewindCurrSLListPos(pSLList pList);
void zapSLList(pSLList pList, void (zapElem)(void*));
int unqueSLListElem(pSLList pList, void* _pElem);
void pushWicStackElem(pWicStack stack, void* elem);
pWicStack createWicStack();
