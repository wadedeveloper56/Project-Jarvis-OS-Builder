
#include "pch.h"
#include "carve.h"
#include "MemorySubsystem.h"
#include "Structs.h"
//#include "msg.h"
//#include "fileio.h"
//#include "alloc.h"
//#include "carve.h"

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


carve_t CarveCreate(shared_ptr<MemorySubsystem> memorySubsystem, size_t elm_size, size_t blk_size)
{
    cv_t* cv;

    elm_size = (elm_size + (sizeof(int) - 1)) & ~(sizeof(int) - 1);
    if (elm_size < sizeof(free_t))
    {
        elm_size = sizeof(free_t);
    }
    //_ChkAlloc(cv, sizeof(*cv));
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

