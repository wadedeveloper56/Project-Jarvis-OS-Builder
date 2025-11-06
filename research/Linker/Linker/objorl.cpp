#include "pch.h"
#include "globals.h"
#include "orl.h"

orl_funcs        ORLFuncs = { read, seek, alloc, free };
orl_handle       ORLHandle;

void* read(void*, size_t) 
{
	return NULL;
}

long int seek(void*, long int, int) 
{
	return 0;
}

void* alloc(size_t)
{
	return NULL;
}

void free(void*) 
{
}
