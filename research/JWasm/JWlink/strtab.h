#pragma once

typedef struct stringblock STRINGBLOCK;

typedef struct {
    STRINGBLOCK* data;
    unsigned    currbase;
} stringtable;

#define STR_BLOCK_SIZE   (4*1024)

typedef struct stringblock {
    STRINGBLOCK* next;
    unsigned    size;
    char        data[STR_BLOCK_SIZE];
} stringblock;

void InitStringTable(stringtable* strtab, bool dontsplit);
void FiniStringTable(stringtable* strtab);
