#pragma once

#include "orlglobl.h"

typedef struct orl_handle_struct* orl_handle;
typedef struct orl_file_handle_struct* orl_file_handle;
typedef struct orl_sec_handle_struct* orl_sec_handle;
typedef struct orl_symbol_handle_struct* orl_symbol_handle;
typedef struct orl_group_handle_struct* orl_group_handle;

#include "orlcomon.h"


typedef struct readcache READCACHE;
typedef struct readcache {
    READCACHE* next;
    void* data;
} readcache;

extern readcache* ReadCacheList;
extern orl_handle ORLHandle;
extern orl_funcs ORLFuncs;

long ORLSeek(void*, long, int);
void* ORLRead(void*, size_t);
void InitObjORL(void);
void ObjORLFini(void);
