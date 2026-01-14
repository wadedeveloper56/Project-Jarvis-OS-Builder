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
