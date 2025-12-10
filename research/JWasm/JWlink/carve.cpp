#include "pch.h"
#include "globals.h"
#include "carve.h"
#include "mem.h"
#include "standard.h"
#include "msg.h"

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
            LnkFatal("carve: freed object was previously freed");
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
        LnkFatal("carve: freed object was never allocated");
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

static blk_t* newBlk(cv_t* cv)
{
    blk_t* newblk;
    blk_t** blklist;

    _ChkAlloc(blk_t*,newblk, sizeof(blk_t) - 1 + cv->blk_size);
    blklist = &cv->blk_list;
    while (*blklist > newblk) {        // keep list sorted by memory address
        blklist = &(*blklist)->next;    // biggest first.
    }
    newblk->next = *blklist;
    *blklist = newblk;
    cv->blk_count++;
    cv->size_chg = TRUE;
    return newblk;
}

static void MakeFreeList(cv_t* cv, blk_t* newblk, unsigned offset)
{
    size_t      elm_size;
    char* top_elm;
    char* bottom_elm;
    char* free_elm;
    free_t* free_list;

    elm_size = cv->elm_size;
    bottom_elm = newblk->data + offset;
    top_elm = newblk->data + cv->blk_top;
    free_list = cv->free_list;
    free_elm = top_elm;
    do {                         /* free_list must be maintained in order */
        free_elm -= elm_size;
        DbgZapFreed(free_elm, elm_size);
        _ADD_TO_FREE(free_list, free_elm);
    } while (free_elm != bottom_elm);
    cv->free_list = free_list;
}

void* CarveAlloc(carve_t cv)
{
    void* p;

    if (cv->free_list == NULL) {
        MakeFreeList(cv, newBlk(cv), 0);
    }
    _REMOVE_FROM_FREE(cv, p);
    DbgZapAlloc(p, cv->elm_size);
    return p;
}

carve_t CarveCreate(size_t elm_size, size_t blk_size)
{
    cv_t* cv;

    elm_size = (elm_size + (sizeof(int) - 1)) & ~(sizeof(int) - 1);
    if (elm_size < sizeof(free_t)) {
        elm_size = sizeof(free_t);
    }
    _ChkAlloc(cv_t*, cv, sizeof(*cv));
    cv->elm_size = elm_size;
    cv->blk_size = blk_size;
    cv->elm_count = cv->blk_size / cv->elm_size;
    cv->blk_top = cv->elm_count * elm_size;
    cv->blk_count = 0;
    cv->blk_list = NULL;
    cv->free_list = NULL;
    cv->blk_map = NULL;
    cv->size_chg = FALSE;
    DbgAssert(cv->elm_size >= 2 * sizeof(void*));
    DbgAssert(cv->elm_count != 0);
    DbgVerify(cv->blk_top < 0x10000, "carve: size * #/block > 64k");
    return(cv);
}

#ifndef NDEBUG
void CarveVerifyAllGone(carve_t cv, char* node_name)
{
    free_t* check;
    blk_t* block;
    char* compare;
    char        buff[80];
    bool        some_unfreed;

    some_unfreed = FALSE;
    for (block = cv->blk_list; block != NULL; block = block->next) {
        compare = block->data + cv->blk_top;
        do {
            compare -= cv->elm_size;
            /* verify every block has been freed */
            for (check = cv->free_list; check != NULL; check = check->next_free) {
                if (compare == (void*)check) break;
            }
            if (check == NULL) {
                if (!some_unfreed) {
                    FmtStr(buff, 80, "carve %s unfreed:", node_name);
                    //WriteStdOut(buff);
                    some_unfreed = TRUE;
                }
                FmtStr(buff, 80, " %h", compare);
                //WriteStdOut(buff);
            }
        } while (compare != block->data);
    }
    if (some_unfreed) {
        //WriteNLStdOut();
    }
}
#endif

void CarveDestroy(carve_t cv)
{
    blk_t* cur;
    blk_t* next;

    if (cv != NULL) {
        if (cv->blk_map != NULL) {
            _LnkFree(cv->blk_map);
        }
        cur = cv->blk_list;
        while (cur != NULL) {
            next = cur->next;
            _LnkFree(cur);
            cur = next;
        }
        _LnkFree(cv);
    }
}
