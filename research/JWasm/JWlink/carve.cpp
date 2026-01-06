#include "pch.h"
#include "globals.h"
#include "carve.h"
#include "MemorySubsystem.h"
#include "debug.h"

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

#ifndef _DEBUG
void CarveVerifyAllGone(MessagingSubsystem* msg,FileSubsystem* file,carve_t cv, char* node_name)
{
    free_t* check;
    blk_t* block;
    char* compare;
    char        buff[80];
    bool        some_unfreed;

    some_unfreed = false;
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
                    msg->FmtStr(buff, 80, "carve %s unfreed:", node_name);
                    file->WriteStdOut(buff,80);
                    some_unfreed = true;
                }
                msg->FmtStr(buff, 80, " %h", compare);
                file->WriteStdOut(buff,80);
            }
        } while (compare != block->data);
    }
    if (some_unfreed) {
        file->WriteNLStdOut();
    }
}
#endif

void CarveDestroy(MemorySubsystem* memory, carve_t cv)
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

#ifndef _DEBUG
void CarveDebugFree(MessagingSubsystem* msg, carve_t cv, void* elm)
{
    free_t* check;
    blk_t* block;
    char* compare;
    char* start;
    size_t esize;

    /* make sure object hasn't been freed before */
    for (check = cv->free_list; check != NULL; check = check->next_free) {
        if (elm == (void*)check) {
            msg->LnkFatal("carve: freed object was previously freed");
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
        msg->LnkFatal("carve: freed object was never allocated");
    }
    DbgZapFreed(elm, cv->elm_size);
}
#else
#define CarveDebugFree( msg, cv, elm )
#endif

void DbgZapAlloc(void* tgt, size_t size)
{
    memset(tgt, 0xA5, size);
}

void DbgZapFreed(void* tgt, size_t size)
{
    memset(tgt, 0xBD, size);
}

blk_t* newBlk(MemorySubsystem* memory, cv_t* cv)
{
    blk_t** blklist;

    _ChkAlloc2(blk_t *, newblk, sizeof(blk_t) - 1 + cv->blk_size);
    blklist = &cv->blk_list;
    while (*blklist > newblk) {        // keep list sorted by memory address
        blklist = &(*blklist)->next;    // biggest first.
    }
    newblk->next = *blklist;
    *blklist = newblk;
    cv->blk_count++;
    cv->size_chg = true;
    return newblk;
}

void CarveFree(MessagingSubsystem* msg, carve_t cv, void* elm)
{
    if (elm == NULL) {
        return;
    }
    CarveDebugFree(msg, cv, elm);
    _ADD_TO_FREE(cv->free_list, elm);
}

void MakeFreeList(cv_t* cv, blk_t* newblk, unsigned offset)
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

void* CarveAlloc(MemorySubsystem* memory, carve_t cv)
{
    void* p;

    if (cv->free_list == NULL) {
        MakeFreeList(cv, newBlk(memory,cv), 0);
    }
    _REMOVE_FROM_FREE(cv, p);
    DbgZapAlloc(p, cv->elm_size);
    return p;
}

carve_t CarveCreate(MemorySubsystem* memory, size_t elm_size, size_t blk_size)
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
    cv->size_chg = false;
    DbgAssert(cv->elm_size >= 2 * sizeof(void*));
    DbgAssert(cv->elm_count != 0);
    DbgVerify(cv->blk_top < 0x10000, "carve: size * #/block > 64k");
    return(cv);
}

