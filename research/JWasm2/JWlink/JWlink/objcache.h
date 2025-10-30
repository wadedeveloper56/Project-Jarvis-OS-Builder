#pragma once

#include "objnode.h"

extern bool     CacheOpen(file_list*);
extern void     CacheClose(file_list*, unsigned);
extern void* CachePermRead(file_list*, unsigned long, unsigned);
extern void* CacheRead(file_list*, unsigned long, unsigned);
extern bool     CacheEnd(file_list*, unsigned long);
extern bool     CacheIsPerm(void);
extern void     CacheFini(void);
extern void     CacheFree(file_list*, void*);
extern void     FreeObjCache(file_list*);
extern bool     DumpObjCache(void);