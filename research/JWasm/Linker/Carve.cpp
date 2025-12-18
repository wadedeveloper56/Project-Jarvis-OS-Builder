#include "pch.h"
#include "Carve.h"

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


Carve::Carve(MemorySubsystem* memory)
{
	this->memory = memory;
}

Carve::~Carve()
{
}

carve_t Carve::CarveCreate(size_t elm_size, size_t blk_size)
{
    cv_t* cv;

    elm_size = (elm_size + (sizeof(int) - 1)) & ~(sizeof(int) - 1);
    if (elm_size < sizeof(free_t)) {
        elm_size = sizeof(free_t);
    }
    cv = (cv_t*)memory->AllocateMemory(sizeof(*cv));
    cv->elm_size = elm_size;
    cv->blk_size = blk_size;
    cv->elm_count = cv->blk_size / cv->elm_size;
    cv->blk_top = cv->elm_count * elm_size;
    cv->blk_count = 0;
    cv->blk_list = NULL;
    cv->free_list = NULL;
    cv->blk_map = NULL;
    cv->size_chg = false;
    return(cv);
}

void Carve::CarveVerifyAllGone(carve_t cv, char* node_name)
{
    free_t* check;
    blk_t* block;
    char* compare;
    //char buff[80];
    bool some_unfreed;

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
                    //FIX ME FmtStr(buff, 80, "carve %s unfreed:", node_name);
                    //FIX ME WriteStdOut(buff);
                    some_unfreed = true;
                }
                //FIX ME FmtStr(buff, 80, " %h", compare);
                //FIX ME WriteStdOut(buff);
            }
        } while (compare != block->data);
    }
    if (some_unfreed) {
        //FIX ME WriteNLStdOut();
    }
}

void Carve::CarveDestroy(carve_t cv)
{
    blk_t* cur;
    blk_t* next;

    if (cv != NULL) {
        if (cv->blk_map != NULL) {
            memory->FreeMemory(cv->blk_map);
        }
        cur = cv->blk_list;
        while (cur != NULL) {
            next = cur->next;
            memory->FreeMemory(cur);
            cur = next;
        }
        memory->FreeMemory(cv);
    }
}

blk_t* Carve::newBlk(cv_t* cv)
{
    blk_t* newblk;
    blk_t** blklist;

    newblk = (blk_t*)memory->AllocateMemory(sizeof(blk_t) - 1 + cv->blk_size);
    blklist = &cv->blk_list;
    while (*blklist > newblk) {        // keep list sorted by memory address
        blklist = &(*blklist)->next;   // biggest first.
    }
    newblk->next = *blklist;
    *blklist = newblk;
    cv->blk_count++;
    cv->size_chg = true;
    return newblk;
}

void Carve::MakeFreeList(cv_t* cv, blk_t* newblk, unsigned offset)
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
        //FIX ME DbgZapFreed(free_elm, elm_size);
        _ADD_TO_FREE(free_list, free_elm);
    } while (free_elm != bottom_elm);
    cv->free_list = free_list;
}

void* Carve::CarveAlloc(carve_t cv)
{
    void* p;

    if (cv->free_list == NULL) {
        MakeFreeList(cv, newBlk(cv), 0);
    }
    _REMOVE_FROM_FREE(cv, p);
    //FIX ME DbgZapAlloc(p, cv->elm_size);
    return p;
}

void* Carve::CarveZeroAlloc(carve_t cv)
{
    void* v;
    unsigned* p;

    if (cv->free_list == NULL) {
        MakeFreeList(cv, newBlk(cv), 0);
    }
    _REMOVE_FROM_FREE(cv, v);
    p = (unsigned*)v;
    //FIX ME DbgAssert((cv->elm_size / sizeof(*p)) <= 16);
    switch (cv->elm_size / sizeof(*p)) {
        case 16:
            p[15] = 0;
        case 15:
            p[14] = 0;
        case 14:
            p[13] = 0;
        case 13:
            p[12] = 0;
        case 12:
            p[11] = 0;
        case 11:
            p[10] = 0;
        case 10:
            p[9] = 0;
        case 9:
            p[8] = 0;
        case 8:
            p[7] = 0;
        case 7:
            p[6] = 0;
        case 6:
            p[5] = 0;
        case 5:
            p[4] = 0;
        case 4:
            p[3] = 0;
        case 3:
            p[2] = 0;
        case 2:
            p[1] = 0;
        case 1:
            p[0] = 0;
    }
    return p;
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
            //FIX ME LnkFatal("carve: freed object was previously freed");
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
        //FIX ME LnkFatal("carve: freed object was never allocated");
    }
    //FIX ME DbgZapFreed(elm, cv->elm_size);
}
#else
#define CarveDebugFree( cv, elm )
#endif

void Carve::CarveFree(carve_t cv, void* elm)
{
    if (elm == NULL) {
        return;
    }
    CarveDebugFree(cv, elm);
    _ADD_TO_FREE(cv->free_list, elm);
}

void* Carve::CarveGetIndex(carve_t cv, void* elm)
{
    blk_t* block;
    unsigned    block_index;

    if (elm == NULL) {
        return((void*)CARVE_NULL_INDEX);
    }
    block_index = (unsigned)cv->blk_count;
    block = cv->blk_list;
    while (elm < (void*)block) {
        --block_index;
        block = block->next;
    }
    //FIX ME DbgAssert(block != NULL);
    return (void*)MK_INDEX(block_index, ((char*)elm) - block->data);
}

void Carve::CarveWalkBlocks(carve_t cv, void (*cbfn)(carve_t, void*, void*),void* cookie)
{
    blk_t* block;

    block = cv->blk_list;
    while (block != NULL) {
        cbfn(cv, block, cookie);
        block = block->next;
    }
}

bool Carve::CarveBlockModified(void* blk)
{
    return ((blk_t*)blk)->modified;
}

void Carve::CarveBlockScan(carve_t cv, void* blk, void (*rtn)(void*, void*),void* data)
{
    char* compare;
    char* end;
    size_t      esize;

    esize = cv->elm_size;
    compare = ((blk_t*)blk)->data;
    end = compare + cv->blk_top;
    do {
        (*rtn)(compare, data);
        compare += esize;
    } while (compare != end);
}

unsigned Carve::CarveBlockSize(carve_t cv)
{
    return cv->blk_size;
}

void* Carve::CarveBlockData(void* block)
{
    return ((blk_t*)block)->data;
}

bool Carve::CarveSizeChanged(carve_t cv)
{
    return cv->size_chg;
}

unsigned Carve::CarveNumElements(carve_t cv)
{
    return cv->blk_count * cv->elm_count;
}

void Carve::CarveWalkAllFree(carve_t cv, void (*rtn)(void*))
{
    free_t* check;

    for (check = cv->free_list; check != NULL; check = check->next_free) {
#ifndef NDEBUG
        free_t* check_next = check->next_free;
        (*rtn)(check);
        if (check->next_free != check_next) {
            //FIX ME LnkFatal("carve walk free routine destroyed links");
        }
#else
        (*rtn)(check);
#endif
    }
}

void Carve::CarveWalkAll(carve_t cv, void (*rtn)(void*, void*), void* data)
{
    blk_t* block;

    for (block = cv->blk_list; block != NULL; block = block->next) {
        CarveBlockScan(cv, block, rtn, data);
    }
}

void Carve::CarveRestart(carve_t cv, unsigned num)
{
    unsigned    numblks;
    unsigned    remainder;
    unsigned    index;
    blk_t* block;

    if (num == 0) return;
    numblks = (num + cv->elm_count - 1) / cv->elm_count;
    for (index = 0; index < numblks; index++) {
        newBlk(cv);
    }
    cv->blk_map = (blk_t**)memory->AllocateMemory(numblks * sizeof(blk_t*));
    index = numblks - 1;
    for (block = cv->blk_list; block != NULL; block = block->next) {
        cv->blk_map[index] = block;
        index -= 1;
    }
    remainder = num % cv->elm_count;
    if (remainder != 0) {
        MakeFreeList(cv, cv->blk_map[0], remainder * cv->elm_size);
    }
    cv->insert = NULL;
}

void Carve::CarveZapBlock(carve_t cv, void* blk, void* dummy)
{
    dummy = dummy;
    MakeFreeList(cv, (blk_t*)blk, 0);
}

void Carve::CarvePurge(carve_t cv)
{
    cv->free_list = NULL;
    CarveWalkBlocks(cv, CarveZapBlock, NULL);
}

void Carve::CarveInsertFree(carve_t cv, void* data)
{
    free_t* freeblk;

    freeblk = (free_t*)data;
    if (cv->insert == NULL) {
        freeblk->next_free = cv->free_list;
        cv->free_list = freeblk;
    }
    else {
        freeblk->next_free = cv->insert->next_free;
        cv->insert->next_free = freeblk;
    }
    cv->insert = freeblk;
}

void* Carve::CarveMapIndex(carve_t cv, void* aindex)
{
    unsigned    index = (unsigned)aindex;
    blk_t* block;
    blk_t** block_map;
    unsigned    block_index;
    unsigned    block_offset;

    /* given an index; find and allocate the carve element */
    if (index == CARVE_NULL_INDEX) {
        return(NULL);
    }
    block_index = GET_BLOCK(index);
    block_offset = GET_OFFSET(index);
    block_map = cv->blk_map;
    block = block_map[block_index - 1];
    return(&(block->data[block_offset]));
}


