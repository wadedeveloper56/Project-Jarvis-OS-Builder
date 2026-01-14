#pragma once

/*---------- Symbol table for storing constants and macros ------------*/

typedef enum {
    SYMT_MACRO,
    SYMT_TYPEDEF
} SymType;

typedef struct SymTabEntry {
    char *name;
    SymType type;
    union {
        pSLList macroCode;
        pDeclInfo typeCode;
        void *data;
    } repr;
} SymTabEntry;


/*----------------- Generic Hash Table and string hash function ---------*/

typedef unsigned HashFunc(void *elem, unsigned size);
typedef HashFunc *pHashFunc;
typedef int HashElemCmp(void *elem1, void *elem2);  // Return 0 iff elem1 == elem2
typedef HashElemCmp *pHashElemCmp;

typedef struct _HTElem {
    void *userData;
    struct _HTElem* next;
} *_pHTElem;

typedef struct {
    _pHTElem *tbl;
    unsigned size;
    pHashFunc hashFunc;
    pHashElemCmp compareFunc; // Take two elements of the table;
                          // Return 0 iff elem1 == elem2
    struct {
        long numElems;
        int longestChainLen;
    } stats;
} *pHTable;

