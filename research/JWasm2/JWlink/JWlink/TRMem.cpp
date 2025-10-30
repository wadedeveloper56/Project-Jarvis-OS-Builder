#include "pch.h"
#include "TRMem.h"

#define msg(a,b)     static const char MSG_##a[]=b
msg(OUT_OF_MEMORY, "Tracker out of memory");
msg(CHUNK_BYTE_UNFREED, "%U chunks (%L bytes) unfreed");
msg(SIZE_ZERO, "%W size zero");
msg(OVERRUN_ALLOCATION, "%W %D overrun allocation by %C of %U bytes");
//msg(UNDERRUN_ALLOCATION,"%W %D underrun allocation by %C of %U bytes" );
msg(UNOWNED_CHUNK, "%W unowned chunk %D");
msg(NULL_PTR, "%W NULL pointer");
msg(NO_ROUTINE, "Tracker was not given a %S routine!");
msg(NOT_IN_ALLOCATION, "%W %D not in any allocation");
msg(OVERRUN_2, "%W %D+%U overruns allocation %D+%U");
msg(PRT_USAGE, "Current usage: %L bytes; Peak usage: %L bytes");
msg(MIN_ALLOC, "%W allocation of %U less than minimum size");
#if defined( M_I86LM ) || defined( M_I86HM )
msg(PRT_LIST_1, "   Who      Addr    Size   Call   Contents");
msg(PRT_LIST_2, "========= ========= ==== ======== ===========================================");
#else
msg(PRT_LIST_1, "  Who      Addr     Size     Call     Contents");
msg(PRT_LIST_2, "======== ======== ======== ======== ===========================================");
#endif
msg(PRT_LIST_3, "%C %D %U %L %X");

TRMem::TRMem(unsigned flags) :alloc_list(NULL), mem_used(0), max_mem(0), min_alloc(0), alloc_no(0), prt_parm(NULL)
{
	this->allocFunc = malloc;
	this->freeFunc = free;
	this->reallocFunc = realloc;
	this->expandFunc = _expand;
	this->prt_lineFunc = PrintLine;
	this->flags = flags;
}

TRMem::~TRMem()
{
	TRMemClose();
}

size_t TRMem::getSize(EntryPtr p)
{
	return(p->size ^ (size_t)p->mem ^ (size_t)p->who ^ (size_t)p);
}

int TRMem::isValidChunk(EntryPtr tr, const char* rtn, TRMemWho who)
{
	size_t size = getSize(tr);
	void* mem = tr->mem;
	size_t blk_size = *(size_t*)_PtrSub(mem, sizeof(size_t));
	if (*(unsigned char*)_PtrAdd(mem, size) != ALLOC_BYTE)
	{
		//trPrt(hdl, MSG_OVERRUN_ALLOCATION, rtn, who, mem, tr->who, size);
		return(0);
	}
	return(1);
}

EntryPtr TRMem::removeFromList(void* mem)
{
	EntryPtrPtr   walk;
	EntryPtr       found;

	walk = &alloc_list;
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

void TRMem::freeEntry(EntryPtr tr)
{
	free(tr);
}

void TRMem::TRMemfree(void* mem, TRMemWho who)
{
	EntryPtr tr;
	size_t size;

	if (mem == NULL) {
		if (flags & _TRMEM_FREE_NULL) {
			trPrt(MSG_NULL_PTR, "Free", who);
		}
		freeFunc(mem);
		return;
	}
	tr = removeFromList(mem);
	if (tr == NULL) {
		trPrt(MSG_UNOWNED_CHUNK, "Free", who, mem);
		return;
	}
	isValidChunk(tr, "Free", who);
	size = getSize(tr);
	mem_used = mem_used - (uint_32)size;
	MEMSET(mem, FREED_BYTE, size + 1);
	freeEntry(tr);
	freeFunc(mem);
}

uint TRMem::TRMemClose()
{
	uint chunks = 0;
	EntryPtr   walk;
	EntryPtr   next;

	if (flags & _TRMEM_CLOSE_CHECK_FREE) {
		uint_32 mem_used = this->mem_used;
		walk = alloc_list;
		while (walk) {
			next = walk->next;
			++chunks;
			TRMemfree(walk->mem, _TRMEM_NO_ROUTINE);
			walk = next;
		}
	}
	else {
		walk = alloc_list;
		while (walk) {
			next = walk->next;
			++chunks;
			freeEntry(walk);
			walk = next;
		}
	}
	return chunks;
}

void TRMem::trPrt(const char* fmt, ...)
{
    va_list     args;
    char        buff[100];
    char* ptr;
    char        ch;
    uint        ui;
    uint_32     ul;
    void* dp;
    TRMemWho  who;
    char* start;
    char* xptr;
    int         i;
    size_t      size;

    va_start(args, fmt);
    ptr = buff;
    for (;;) {
        ch = *fmt++;
        if (ch == '\0') break;
        if (ch == '%') {
            ch = *fmt++;
            switch (ch) {
                case 'W':   /* "a1(a2):" */
                    ptr = stpcpy(ptr, va_arg(args, const char*));
                    who = va_arg(args, TRMemWho);
                    if (who != _TRMEM_NO_ROUTINE) {
                        *ptr++ = '(';
                        ptr = formHex(ptr, (size_t)who, sizeof(who));
                        *ptr++ = ')';
                    }
                    *ptr++ = ':';
                    break;
                case 'C':   /* code pointer */
                    who = va_arg(args, TRMemWho);
                    ptr = formCodePtr(ptr, who);
                    break;
                case 'D':   /* data pointer */
                    dp = va_arg(args, void*);
                    ptr = formHex(ptr, (size_t)dp, sizeof(dp));
                    break;
                case 'S':   /* char * (string) pointer */
                    ptr = stpcpy(ptr, va_arg(args, char*));
                    break;
                case 'U':   /* unsigned integer */
                    ui = va_arg(args, uint);
                    ptr = formHex(ptr, (size_t)ui, sizeof(ui));
                    break;
                case 'L':   /* unsigned long */
                    ul = va_arg(args, uint_32);
                    ptr = formHex(ptr, (size_t)ul, sizeof(ul));
                    break;
                case 'X':   /* 14 bytes of hex data */
                    start = va_arg(args, char*);
                    size = va_arg(args, size_t);
                    if (size > 14) size = 14;
                    xptr = start;
                    for (i = 0; i < 14; i++) {
                        if (i < (int)size) {
                            ptr = formHex(ptr, *xptr, sizeof(char));
                            xptr++;
                        }
                        else {    // no more to print, so make things line up.
                            *ptr = ' ';
                            *(ptr + 1) = ' ';
                            ptr += 2;
                        }
                        if (i == 7) {
                            *ptr = ' ';
                            ptr++;
                        }
                    }
                    for (i = 0; i < (int)size; i++) {
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
    prt_lineFunc(prt_parm, buff, ptr - buff);
}

char* TRMem::formCodePtr(char* ptr, TRMemWho who)
{
    return formHex(ptr, (size_t)who, sizeof(who));
}

void TRMem::setSize(EntryPtr p, size_t size)
{
    p->size = size ^ (size_t)p->mem ^ (size_t)p->who ^ (size_t)p;
}

EntryPtr TRMem::allocEntry()
{
    EntryPtr   tr = (EntryPtr)allocFunc(sizeof(Entry));
    if (tr == NULL && (flags & _TRMEM_OUT_OF_MEMORY)) {
        trPrt(MSG_OUT_OF_MEMORY);
    }
    return(tr);
}

void TRMem::addToList(EntryPtr tr)
{
    tr->next = alloc_list;
    alloc_list = tr;
}

void* TRMem::ChangeAlloc(void* old, size_t size, TRMemWho who, void* (*fn)(void*, size_t),  char* name)
{
    EntryPtr   tr;
    void* new_block;
    size_t      old_size;

    if (fn == (void*)_TRMEM_NO_ROUTINE) {
        trPrt(MSG_NO_ROUTINE, name);
        return(NULL);
    }

    if (size == 0) {
        if (flags & _TRMEM_REALLOC_SIZE_0) {
            trPrt(MSG_SIZE_ZERO, name, who);
        }
        if (old == NULL) {
            if (flags & _TRMEM_REALLOC_NULL) {
                trPrt(MSG_NULL_PTR, name, who);
            }
            return(fn(NULL, 0));
        }

        /* old != NULL */
        tr = removeFromList(old);
        if (tr == NULL) {
            trPrt(MSG_UNOWNED_CHUNK, name, who, old);
            return(NULL);
        }
        isValidChunk(tr, name, who);
        size = getSize(tr);
        mem_used -= (uint_32)size;
        MEMSET(old, FREED_BYTE, size + 1);
        freeEntry(tr);
        return(fn(old, 0));
    }

    /* size != 0 */
    if (old == NULL) {
        if (flags & _TRMEM_REALLOC_NULL) {
            trPrt(MSG_NULL_PTR, name, who);
        }
        new_block = fn(NULL, size + 1);
        if (new_block != NULL) {
            MEMSET(new_block, ALLOC_BYTE, size + 1);
            tr = allocEntry();
            if (tr != NULL) {
                tr->mem = new_block;
                tr->who = who;
                setSize(tr, size);
                addToList(tr);
            }
            mem_used += (uint_32)size;
            if (mem_used > max_mem) {
                max_mem = mem_used;
            }
        }
        return(new_block);
    }

    /* old != NULL && size != 0 */
    tr = removeFromList(old);
    if (tr == NULL) {
        trPrt(MSG_UNOWNED_CHUNK, name, who, old);
        return(NULL);
    }
    if (!isValidChunk(tr, name, who)) {
        return(NULL);
    }
    new_block = fn(old, size + 1);
    if (new_block == NULL) {
        addToList(tr);   /* put back on list without change */
        return(new_block);
    }
    old_size = getSize(tr);
    if (size > old_size) {
        MEMSET(_PtrAdd(new_block, old_size), ALLOC_BYTE, size + 1 - old_size);
    }
    else {
        *(unsigned char*)_PtrAdd(new_block, size) = ALLOC_BYTE;
    }
    mem_used -= (uint_32)old_size;
    mem_used += (uint_32)size;
    if (mem_used > max_mem) {
        max_mem = mem_used;
    }
    tr->mem = new_block;
    tr->who = who;
    setSize(tr, size);
    addToList(tr);
    return(new_block);
}

void* TRMem::TRMemRealloc(void* old, size_t size,TRMemWho who)
{
    return(ChangeAlloc(old, size, who, realloc, (char *)"Realloc"));
}

char* stpcpy(char* dest, const char* src)
{
    *dest = *src;
    while (*dest) {
        ++dest;
        ++src;
        *dest = *src;
    }
    return(dest);
}

char* formHex(char* ptr, size_t data, uint size)
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

void PrintLine(FILE* bogus, const char* buff, size_t len)
{
}