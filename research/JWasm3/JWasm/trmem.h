#pragma once

#include "inttype.h"
#include <stddef.h>

typedef void (*_trmem_who)(void);  /* generic pointer to code */
#define _TRMEM_NO_ROUTINE   ((_trmem_who)0)

/* generic pointer to code with realloc signature */
typedef void* (*_trmem_realloc_who)(void*, size_t);
#define _TRMEM_NO_REALLOC ((_trmem_realloc_who)0)

typedef struct Entry {
    Entry *next;
    void* mem;
    _trmem_who who;
    size_t size;       // real size = tr ^ mem ^ who ^ size
    uint_32 when;
}entry, * entry_ptr, ** entry_ptr_ptr;

typedef struct _trmem_internal {
    entry_ptr   alloc_list;
    uint_32     mem_used;
    uint_32     max_mem;
    uint_32     alloc_no;
    void* (*alloc)(size_t);
    void        (*free)(void*);
    void* (*realloc)(void*, size_t);
    void* (*expand)(void*, size_t);
    FILE* prt_parm;
    void        (*prt_line)(FILE*, const char*, size_t);
    uint        flags;
    size_t      min_alloc;
}* _trmem_hdl;

enum {
    _TRMEM_ALLOC_SIZE_0 = 0x0001,/* attempted alloc of size 0 */
    _TRMEM_REALLOC_SIZE_0 = 0x0002,/* attempted realloc/expand of size 0 */
    _TRMEM_REALLOC_NULL = 0x0004,/* attempted realloc/expand of a NULL ptr */
    _TRMEM_FREE_NULL = 0x0008,/* attempted free of a NULL pointer */
    _TRMEM_OUT_OF_MEMORY = 0x0010,/* warn if trmem can't allocate memory for its own purposes */
    _TRMEM_CLOSE_CHECK_FREE = 0x0020 /* _trmem_close checks if all chunks were freed */
};

static char* stpcpy(char* dest, const char* src);
static char* formHex(char* ptr, size_t data, uint size);
#if defined(M_I86LM) || defined(M_I86HM) || defined(M_I86MM) || defined(M_I86CM)
static char* formFarPtr(char* ptr, void far* data);
#endif
static char* formCodePtr(_trmem_hdl hdl, char* ptr, _trmem_who who);
static void trPrt(_trmem_hdl hdl, const char* fmt, ...);
static entry_ptr allocEntry(_trmem_hdl hdl);
static void freeEntry(entry_ptr tr, _trmem_hdl hdl);
static void addToList(entry_ptr tr, _trmem_hdl hdl);
static entry_ptr findOnList(void* mem, _trmem_hdl hdl);
static entry_ptr removeFromList(void* mem, _trmem_hdl hdl);
_trmem_hdl _trmem_open(void* (*alloc)(size_t), void (*free)(void*), void* (*realloc)(void*, size_t), void* (*expand)(void*, size_t), FILE* prt_parm, void (*prt_line)(FILE*, const char*, size_t), unsigned flags);
int _trmem_validate_all(_trmem_hdl hdl);
unsigned _trmem_close(_trmem_hdl hdl);
void _trmem_set_min_alloc(size_t size, _trmem_hdl hdl);
void* _trmem_alloc(size_t size, _trmem_who who, _trmem_hdl hdl);
static int isValidChunk(entry_ptr tr, const char* rtn, _trmem_who who, _trmem_hdl hdl);
int _trmem_validate(void* mem, _trmem_who who, _trmem_hdl hdl);
void _trmem_free(void* mem, _trmem_who who, _trmem_hdl hdl);
static void* ChangeAlloc(void* old, size_t size, _trmem_who who, _trmem_hdl hdl, void* (*fn)(void*, size_t), char* name);
void* _trmem_realloc(void* old, size_t size, _trmem_who who, _trmem_hdl hdl);
void* _trmem_expand(void* old, size_t size, _trmem_who who, _trmem_hdl hdl);
char* _trmem_strdup(const char* str, _trmem_who who, _trmem_hdl hdl);
int _trmem_chk_range(void* start, size_t len, _trmem_who who, _trmem_hdl hdl);
void _trmem_prt_usage(_trmem_hdl hdl);
unsigned _trmem_prt_list(_trmem_hdl hdl);
size_t _trmem_msize(void* mem, _trmem_hdl hdl);
unsigned long _trmem_get_current_usage(_trmem_hdl hdl);
unsigned long _trmem_get_peak_usage(_trmem_hdl hdl);
#ifndef __WATCOMC__
    _trmem_who  _trmem_guess_who(void* p);
#endif
#if !defined(_M_IX86) || !defined(__WATCOMC__)
    _trmem_who  _trmem_whoami(void);
#endif

extern _trmem_hdl  hTrmem;
extern FILE* FileTrmem;

#define TRMEM_LOGFN "~jwasm.trk"

static void memLine(FILE* fh, const char* buf, size_t size);
void tm_Init(void);
void tm_Fini(void);
