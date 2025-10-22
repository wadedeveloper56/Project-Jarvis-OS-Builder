#pragma once

#define TRMEM_LOGFN "~jwasm.trk"

typedef unsigned long long   uint_64;
typedef unsigned long   uint_32;
typedef unsigned        uint;
typedef void (*_trmem_who)(void);       

typedef void* (*_trmem_realloc_who)(void*, size_t);
#define _TRMEM_NO_REALLOC ((_trmem_realloc_who)0)

typedef void (*_trmem_who)(void);       
#define _TRMEM_NO_ROUTINE   ((_trmem_who)0)

#define msg(a,b)     static const char MSG_##a[]=b

#define _PtrAdd( p, i ) ((void *)((char *)(p) + i))
#define _PtrSub( p, i ) ((void *)((char *)(p) - i))
#define _PtrCmp(a,op,b) ((void *)(a) op (void *)(b))

#define ALLOC_BYTE      0xA5
#define FREED_BYTE      0xBD

#define MEMSET(p,c,l)   memset(p,c,l)

enum {
	_TRMEM_ALLOC_SIZE_0 = 0x0001,      
	_TRMEM_REALLOC_SIZE_0 = 0x0002,      
	_TRMEM_REALLOC_NULL = 0x0004,       
	_TRMEM_FREE_NULL = 0x0008,       
	_TRMEM_OUT_OF_MEMORY = 0x0010,      
	_TRMEM_CLOSE_CHECK_FREE = 0x0020      
};

typedef struct Entry {
	struct Entry *next;
	void* mem;
	_trmem_who      who;
	size_t          size;                 
	uint_32         when;
} entry, * entry_ptr, ** entry_ptr_ptr;

typedef struct _trmem_internal {
	entry_ptr   alloc_list;
#ifdef _WIN64
	uint_64     mem_used;
	uint_64     max_mem;
#else
	uint_32     mem_used;
	uint_32     max_mem;
#endif
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

void tm_Init(void);
void tm_Fini(void);
