#include "Assembler.h"

fatal_func nasm_alloc_failed(void)
{
    nasm_critical("out of memory!");
}

void* nasm_malloc(size_t size)
{
    void* p;

again:
    p = malloc(size);

    if (unlikely(!p)) {
        if (!size) {
            size = 1;
            goto again;
        }
        nasm_alloc_failed();
    }
    return p;
}

void* nasm_calloc(size_t nelem, size_t size)
{
    void* p;

again:
    p = calloc(nelem, size);

    if (unlikely(!p)) {
        if (!nelem || !size) {
            nelem = size = 1;
            goto again;
        }
        nasm_alloc_failed();
    }

    return p;
}

void* nasm_zalloc(size_t size)
{
	return nasm_calloc(size, 1);
}

struct strlist* strlist_alloc(bool uniq)
{
	struct strlist* list = (struct strlist* )nasm_zalloc(sizeof(*list));
	list->tailp = &list->head;
	list->uniq = uniq;
	return list;
}