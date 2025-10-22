#include "pch.h"
#include "trmem.h"

_trmem_hdl  hTrmem;
FILE* FileTrmem;
msg(OUT_OF_MEMORY, "Tracker out of memory");
msg(CHUNK_BYTE_UNFREED, "%U chunks (%L bytes) unfreed");
msg(SIZE_ZERO, "%W size zero");
msg(OVERRUN_ALLOCATION, "%W %D overrun allocation by %C of %U bytes");
msg(UNOWNED_CHUNK, "%W unowned chunk %D");
msg(NULL_PTR, "%W NULL pointer");
msg(NO_ROUTINE, "Tracker was not given a %S routine!");
msg(NOT_IN_ALLOCATION, "%W %D not in any allocation");
msg(OVERRUN_2, "%W %D+%U overruns allocation %D+%U");
msg(PRT_USAGE, "Current usage: %L bytes; Peak usage: %L bytes");
msg(MIN_ALLOC, "%W allocation of %U less than minimum size");
msg(PRT_LIST_1, "  Who      Addr     Size     Call     Contents");
msg(PRT_LIST_2, "======== ======== ======== ======== ===========================================");
msg(PRT_LIST_3, "%C %D %U %L %X");


_trmem_hdl _trmem_open(
	void* (*alloc)(size_t),
	void (*free)(void*),
	void* (*realloc)(void*, size_t),
	void* (*expand)(void*, size_t),
	FILE* prt_parm,
	void (*prt_line)(FILE*, const char*, size_t),
	unsigned flags)
{
	_trmem_hdl  hdl = (_trmem_hdl)alloc(sizeof(struct _trmem_internal));
	if (hdl == NULL) {
		return(NULL);
	}
	hdl->alloc = alloc;
	hdl->free = free;
	hdl->realloc = realloc;
	hdl->expand = expand;
	hdl->prt_parm = prt_parm;
	hdl->prt_line = prt_line;
	hdl->flags = flags;
	hdl->alloc_list = NULL;
	hdl->mem_used = 0;
	hdl->max_mem = 0;
	hdl->min_alloc = 0;
	hdl->alloc_no = 0;
	return(hdl);
}

static char* stpcpy(char* dest, const char* src)
{
	*dest = *src;
	while (*dest) {
		++dest;
		++src;
		*dest = *src;
	}
	return(dest);
}

#ifdef _WIN64
static char* formHex(char* ptr, uint_64 data, uint size)
#else
static char* formHex(char* ptr, uint_32 data, uint size)
#endif
{
	char* str;

	size *= 2;
	ptr += size;
	str = ptr;
	for (; size > 0; size--) {
		*--str = "0123456789abcdef"[data & 0x0f];
		data >>= 4;
	}
	return(ptr);
}

static char* formCodePtr(_trmem_hdl hdl, char* ptr, _trmem_who who)
{
#ifdef _WIN64
	return formHex(ptr, (uint_64)who, sizeof(who));
#else
	return formHex(ptr, (uint_32)who, sizeof(who));
#endif
}

static void trPrt(_trmem_hdl hdl, const char* fmt, ...)
{
	va_list     args;
	char        buff[100];
	char* ptr;
	char        ch;
	uint        ui;
	uint_32     ul;
	void* dp;
	_trmem_who  who;
	char* start;
	char* xptr;
	//int         i;
	size_t      size;

	va_start(args, fmt);
	ptr = buff;
	for (;;) {
		ch = *fmt++;
		if (ch == '\0') break;
		if (ch == '%') {
			ch = *fmt++;
			switch (ch) {
				case 'W':
					ptr = stpcpy(ptr, va_arg(args, const char*));
					who = va_arg(args, _trmem_who);
					if (who != _TRMEM_NO_ROUTINE) {
						*ptr++ = '(';
#ifdef _WIN64
						ptr = formHex(ptr, (uint_64)who, sizeof(who));
#else
						ptr = formHex(ptr, (uint_32)who, sizeof(who));
#endif

						* ptr++ = ')';
					}
					*ptr++ = ':';
					break;
				case 'C':
					who = va_arg(args, _trmem_who);
					ptr = formCodePtr(hdl, ptr, who);
					break;
				case 'D':
					dp = va_arg(args, void*);
#ifdef _WIN64
					ptr = formHex(ptr, (uint_64)dp, sizeof(dp));
#else
					ptr = formHex(ptr, (uint_32)dp, sizeof(dp));
#endif
					break;
				case 'S':
					ptr = stpcpy(ptr, va_arg(args, char*));
					break;
				case 'U':
					ui = va_arg(args, uint);
					ptr = formHex(ptr, (uint_32)ui, sizeof(ui));
					break;
				case 'L':
					ul = va_arg(args, uint_32);
					ptr = formHex(ptr, (uint_32)ul, sizeof(ul));
					break;
				case 'X':
					start = va_arg(args, char*);
					size = va_arg(args, size_t);
					if (size > 14) size = 14;
					xptr = start;
					for (size_t i = 0; i < 14; i++) {
						if (i < size) {
							ptr = formHex(ptr, *xptr, sizeof(char));
							xptr++;
						}
						else {
							*ptr = ' ';
							*(ptr + 1) = ' ';
							ptr += 2;
						}
						if (i == 7) {
							*ptr = ' ';
							ptr++;
						}
					}
					for (size_t i = 0; i < size; i++) {
						if (isprint(*start)) {
							*ptr = *start;
						}
						else {
							*ptr = '.';
						}
						ptr++;
						start++;
					}
					break;
				default:
					*ptr++ = ch;
					break;
			}
		}
		else {
			*ptr++ = ch;
		}
	}
	va_end(args);
	*ptr++ = '\n';
	*ptr = '\0';
	hdl->prt_line(hdl->prt_parm, buff, ptr - buff);
}

static entry_ptr removeFromList(void* mem, _trmem_hdl hdl)
{
	entry_ptr_ptr   walk;
	entry_ptr       found;

	walk = &hdl->alloc_list;
	while (*walk) {
		if (_PtrCmp((*walk)->mem, == , mem)) {
			found = *walk;
			*walk = found->next;
			return(found);
		}
		walk = &(*walk)->next;
	}
	return(NULL);
}


static void setSize(entry_ptr p, size_t size)
{
	p->size = size ^ (size_t)p->mem ^ (size_t)p->who ^ (size_t)p;
}

static size_t getSize(entry_ptr p)
{
	return(p->size ^ (size_t)p->mem ^ (size_t)p->who ^ (size_t)p);
}

static int isValidChunk(entry_ptr tr, const char* rtn, _trmem_who who, _trmem_hdl hdl)
{
	void* mem;
	size_t size;
	size_t blk_size;

	size = getSize(tr);
	mem = tr->mem;
	blk_size = *(size_t*)_PtrSub(mem, sizeof(size_t));
	if (*(unsigned char*)_PtrAdd(mem, size) != ALLOC_BYTE) {
		trPrt(hdl, MSG_OVERRUN_ALLOCATION, rtn, who, mem, tr->who, size);
		return(0);
	}
	return(1);
}

static void freeEntry(entry_ptr tr, _trmem_hdl hdl)
{
	hdl->free(tr);
}

void _trmem_free(void* mem, _trmem_who who, _trmem_hdl hdl)
{
	entry_ptr   tr;
	size_t      size;

	if (mem == NULL) {
		if (hdl->flags & _TRMEM_FREE_NULL) {
			trPrt(hdl, MSG_NULL_PTR, "Free", who);
		}
		hdl->free(mem);
		return;
	}
	tr = removeFromList(mem, hdl);
	if (tr == NULL) {
		trPrt(hdl, MSG_UNOWNED_CHUNK, "Free", who, mem);
		return;
	}
	isValidChunk(tr, "Free", who, hdl);
	size = getSize(tr);
	hdl->mem_used -= size;
	MEMSET(mem, FREED_BYTE, size + 1);
	freeEntry(tr, hdl);
	hdl->free(mem);
}

void _trmem_prt_usage(_trmem_hdl hdl)
{
	trPrt(hdl, MSG_PRT_USAGE, hdl->mem_used, hdl->max_mem);
}

unsigned _trmem_prt_list(_trmem_hdl hdl)
{
	entry_ptr   tr;
	unsigned    chunks;
	size_t      size;

	tr = hdl->alloc_list;
	if (tr == 0) return(0);
	_trmem_prt_usage(hdl);
	trPrt(hdl, MSG_PRT_LIST_1);
	trPrt(hdl, MSG_PRT_LIST_2);
	chunks = 0;
	do {
		size = getSize(tr);
		if (chunks < 20) {
			trPrt(hdl
				, MSG_PRT_LIST_3
				, tr->who
				, tr->mem
				, size
				, tr->when
				, tr->mem
				, size);
		}
		++chunks;
		tr = tr->next;
	} while (tr);
	return(chunks);
}

unsigned _trmem_close(_trmem_hdl hdl)
{
	uint        chunks;
#ifdef _WIN64
	uint_64     mem_used;
#else
	uint_32     mem_used;
#endif
	entry_ptr   walk;
	entry_ptr   next;

	chunks = 0;
	if (hdl->flags & _TRMEM_CLOSE_CHECK_FREE) {
		mem_used = hdl->mem_used;
		walk = hdl->alloc_list;
		while (walk) {
			next = walk->next;
			++chunks;
			_trmem_free(walk->mem, _TRMEM_NO_ROUTINE, hdl);
			walk = next;
		}
		if (chunks) {
			trPrt(hdl, MSG_CHUNK_BYTE_UNFREED, chunks, mem_used);
		}
	}
	else {
		walk = hdl->alloc_list;
		while (walk) {
			next = walk->next;
			++chunks;
			freeEntry(walk, hdl);
			walk = next;
		}
	}
	hdl->free(hdl);
	return(chunks);
}

void memLine(FILE* fh, const char* buf, size_t size)
{
	fwrite(buf, 1, size, fh);
}

void tm_Init(void)
{
	if (FileTrmem = fopen(TRMEM_LOGFN, "w")) {
		hTrmem = _trmem_open(malloc, free, _TRMEM_NO_REALLOC, _TRMEM_NO_REALLOC, FileTrmem, memLine, _TRMEM_ALLOC_SIZE_0 | _TRMEM_FREE_NULL | _TRMEM_OUT_OF_MEMORY | _TRMEM_CLOSE_CHECK_FREE);
		if (hTrmem == NULL) {
			printf("tm_Init: _trmem_open() failed\n");
			exit(EXIT_FAILURE);
		}
	}
	else {
		printf("tm_Init: fopen(\"" TRMEM_LOGFN "\") failed [%u]\n", errno);
		exit(EXIT_FAILURE);
	}
}

void tm_Fini(void)
{
	_trmem_prt_list(hTrmem);
	_trmem_close(hTrmem);
	fclose(FileTrmem);
}