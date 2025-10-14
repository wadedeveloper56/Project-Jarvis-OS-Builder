#include "jasm.h"

static void* def_xmalloc(size_t size)
{
    void* newmem;
    if (size == 0) size = 1;
    newmem = malloc(size);
    if (!newmem) yasm__fatal("out of memory");
    return newmem;
}

void* (*yasm_xmalloc) (size_t size) = def_xmalloc;