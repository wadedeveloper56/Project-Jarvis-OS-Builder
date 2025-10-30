#pragma once
#include "watcom.h"
enum {
    _TRMEM_ALLOC_SIZE_0 = 0x0001,/* attempted alloc of size 0 */
    _TRMEM_REALLOC_SIZE_0 = 0x0002,/* attempted realloc/expand of size 0 */
    _TRMEM_REALLOC_NULL = 0x0004,/* attempted realloc/expand of a NULL ptr */
    _TRMEM_FREE_NULL = 0x0008,/* attempted free of a NULL pointer */
    _TRMEM_OUT_OF_MEMORY = 0x0010,/* warn if trmem can't allocate memory for its own purposes */
    _TRMEM_CLOSE_CHECK_FREE = 0x0020 /* _trmem_close checks if all chunks were freed */
};
typedef void (*TRMemWho)(void);  /* generic pointer to code */
#define _TRMEM_NO_ROUTINE   ((TRMemWho)0)

/* generic pointer to code with realloc signature */
typedef void* (*_trmem_realloc_who)(void*, size_t);
#define _TRMEM_NO_REALLOC ((_trmem_realloc_who)0)

#define MEMSET(p,c,l)   memset(p,c,l)
#define ALLOC_BYTE      0xA5
#define FREED_BYTE      0xBD
#define _PtrAdd( p, i ) ((void *)((char *)(p) + i))
#define _PtrSub( p, i ) ((void *)((char *)(p) - i))
#define _PtrCmp(a,op,b) ((void *)(a) op (void *)(b))

typedef struct _Entry {
    struct _Entry *next;
    void* mem;
    TRMemWho who;
    size_t size;       // real size = tr ^ mem ^ who ^ size
    uint_32 when;
}Entry, * EntryPtr, ** EntryPtrPtr;

class TRMem
{
    EntryPtr alloc_list;
    void* (*allocFunc)(size_t);
    void (*freeFunc)(void*);
    void* (*reallocFunc)(void*, size_t);
    void* (*expandFunc)(void*, size_t);
    FILE* prt_parm;
    void (*prt_lineFunc)(FILE*, const char*, size_t);
    unsigned flags;
    uint_32     mem_used;
    uint_32     max_mem;
    uint_32     alloc_no;
    size_t      min_alloc;
public:
    TRMem(unsigned flags);
    ~TRMem();
    uint TRMemClose();
    void TRMemfree(void* mem, TRMemWho who);
    void freeEntry(EntryPtr tr);
    EntryPtr removeFromList(void* mem);
    int isValidChunk(EntryPtr tr, const char* rtn, TRMemWho who);
    size_t getSize(EntryPtr p);
    void trPrt(const char* fmt, ...);
    char* formCodePtr(char* ptr, TRMemWho who);
    void* alloc(size_t amount) { return allocFunc(amount); }
    void* ChangeAlloc(void* old, size_t size, TRMemWho who, void* (*fn)(void*, size_t), char* name);
    void* TRMemRealloc(void* old, size_t size, TRMemWho who);
    void setSize(EntryPtr p, size_t size);
    EntryPtr allocEntry();
    void addToList(EntryPtr tr);
};
char* formHex(char* ptr, size_t data, uint size);
char* stpcpy(char* dest, const char* src);
void PrintLine(FILE* bogus, const char* buff, size_t len);
