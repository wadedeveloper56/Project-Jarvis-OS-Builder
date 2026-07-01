
#include "pch.h"
#include "carve.h"
#include "MemorySubsystem.h"
#include "Structs.h"

#define MK_INDEX( b, o )        (((b)<<16)|(o))
#define GET_BLOCK( i )          (((i)>>16)&0x0ffff)
#define GET_OFFSET( i )         ((i)&0x0ffff)
typedef struct blk blk_t;
typedef struct free_t free_t;

struct blk
{
    blk_t* next;
    unsigned    index;
    unsigned    modified : 1;
    unsigned : 15;
    char        data[1];
};

struct free_t
{
    free_t* next_free;
};

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


carve_t CarveCreate(MemorySubsystem *memorySubsystem, size_t elm_size, size_t blk_size)
{
    cv_t* cv;

    elm_size = (elm_size + (sizeof(int) - 1)) & ~(sizeof(int) - 1);
    if (elm_size < sizeof(free_t))
    {
        elm_size = sizeof(free_t);
    }
	cv = (cv_t*)memorySubsystem->AllocateMemory(sizeof(*cv));
    cv->elm_size = elm_size;
    cv->blk_size = blk_size;
    cv->elm_count = cv->blk_size / cv->elm_size;
    cv->blk_top = cv->elm_count * elm_size;
    cv->blk_count = 0;
    cv->blk_list = NULL;
    cv->free_list = NULL;
    cv->blk_map = NULL;
    cv->size_chg = false;
    //DbgAssert(cv->elm_size >= 2 * sizeof(void*));
    //DbgAssert(cv->elm_count != 0);
    //DbgVerify(cv->blk_top < 0x10000, "carve: size * #/block > 64k");
    return(cv);
}

#define CarveDebugFree( cv, elm )

void CarveFree(carve_t cv, void* elm)
{
    if (elm == NULL)
    {
        return;
    }
    CarveDebugFree(cv, elm);
    _ADD_TO_FREE(cv->free_list, elm);
}

void CarveDestroy(MemorySubsystem *memorySubsystem, carve_t cv)
{
    blk_t* cur;
    blk_t* next;

    if (cv != NULL)
    {
        if (cv->blk_map != NULL)
        {
            _LnkFree(cv->blk_map);
        }
        cur = cv->blk_list;
        while (cur != NULL)
        {
            next = cur->next;
            _LnkFree(cur);
            cur = next;
        }
        _LnkFree(cv);
    }
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
    for (block = cv->blk_list; block != NULL; block = block->next)
    {
        compare = block->data + cv->blk_top;
        do
        {
            compare -= cv->elm_size;
            /* verify every block has been freed */
            for (check = cv->free_list; check != NULL; check = check->next_free)
            {
                if (compare == (void*)check) break;
            }
            if (check == NULL)
            {
                if (!some_unfreed)
                {
                    //FmtStr(buff, 80, "carve %s unfreed:", node_name);
                    //WriteStdOut(buff);
                    some_unfreed = TRUE;
                }
                //FmtStr(buff, 80, " %h", compare);
                //WriteStdOut(buff);
            }
        } while (compare != block->data);
    }
    if (some_unfreed)
    {
        //WriteNLStdOut();
    }
}
#endif
