#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "fileio.h"
#include "alloc.h"
#include "carve.h"

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
    //DbgAssert(cv->elm_size >= 2 * sizeof(void*));
    //DbgAssert(cv->elm_count != 0);
    //DbgVerify(cv->blk_top < 0x10000, "carve: size * #/block > 64k");
    return(cv);
}
