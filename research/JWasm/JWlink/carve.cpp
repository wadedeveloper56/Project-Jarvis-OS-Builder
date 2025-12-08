#include "pch.h"
#include "carve.h"
#include "msg.h"
#include "wlmsgs.h"
#include "linkutil.h"
#include "mem.h"

struct blk {
    blk_t* next;
    unsigned    index;
    unsigned    modified : 1;
    unsigned : 15;
    char        data[1];
};

struct free_t {
    free_t* next_free;
};


// assumes '->free_list' is non-NULL
#define _REMOVE_FROM_FREE( pcv, p ) \
    { \
        free_t *head = pcv->free_list; \
        pcv->free_list = head->next_free; \
        p = head; \
    }

#define _ADD_TO_FREE( fl, p ) \
    { \
        free_t *node = (free_t *) (p); \
        node->next_free = (fl); \
        (fl) = node; \
    }

#ifndef NDEBUG
void CarveDebugFree(carve_t cv, void* elm)
{
    free_t* check;
    blk_t* block;
    char* compare;
    char* start;
    size_t esize;

    /* make sure object hasn't been freed before */
    for (check = cv->free_list; check != NULL; check = check->next_free) {
        if (elm == (void*)check) {
            LnkFatal((char *)"carve: freed object was previously freed");
        }
    }
    /* make sure object is from this carve allocator */
    for (block = cv->blk_list; block != NULL; block = block->next) {
        start = block->data;
        compare = start + cv->blk_top;
#if ! ( defined(__COMPACT__) || defined(__LARGE__) )
        /* quick check */
        if (elm < start || elm > compare) {
            continue;
        }
#endif
        esize = cv->elm_size;
        for (;;) {
            if (compare == start) break;
            compare -= esize;
            if (elm == compare) break;
        }
        if (elm == compare) break;
    }
    if (block == NULL) {
        LnkFatal((char*)"carve: freed object was never allocated");
    }
    DbgZapFreed(elm, cv->elm_size);
}
#else
#define CarveDebugFree( cv, elm )
#endif

void CarveFree(carve_t cv, void* elm)
{
    if (elm == NULL) {
        return;
    }
    CarveDebugFree(cv, elm);
    _ADD_TO_FREE(cv->free_list, elm);
}