#include "pch.h"
#include "strtab.h"
#include "Structs.h"
#include "MemorySubsystem.h"
#include "ring.h"

using namespace std;
#define STR_BLOCK_SIZE   (4*1024)

stringblock* AllocNewBlock(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab)
{
	stringblock* blk = (stringblock*)memorySubsystem->AllocateMemory(sizeof(stringblock));
    blk->next = NULL;
    RingAppend(&strtab->data, blk);
    blk->size = 0;
    return blk;
}

void InitStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, bool dontsplit)
{
    strtab->data = NULL;
    if (dontsplit)
    {
        strtab->currbase = 1;
    }
    else
    {
        strtab->currbase = 0;
    }
    AllocNewBlock(memorySubsystem, strtab);
}

char* AddToStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, void* data, unsigned len, bool addnullchar)
{
    stringblock* blk;
    unsigned    diff;
    char* dest;

    if (addnullchar)
        ++len;
    blk = (stringblock*)RingLast(strtab->data);
    if (strtab->currbase & 1 && len > STR_BLOCK_SIZE)
    {
        //LnkMsg(ERR + MSG_SYMBOL_NAME_TOO_LONG, "s", data);
        len = STR_BLOCK_SIZE;
    }
    while (blk->size + len > STR_BLOCK_SIZE)
    {
        diff = STR_BLOCK_SIZE - blk->size;
        if (diff != 0)
        {
            if (strtab->currbase & 1)
            {           
                memset(&blk->data[blk->size], 0, diff);
            }
            else
            {
                memcpy(&blk->data[blk->size], data, diff);
                len -= diff;
                data = (char*)data + diff;
            }
        }
        blk->size = STR_BLOCK_SIZE;
        strtab->currbase += STR_BLOCK_SIZE;
        blk = AllocNewBlock(memorySubsystem, strtab);
    }
    dest = &blk->data[blk->size];
    blk->size += len;
    if (addnullchar)
        dest[--len] = '\0';
    memcpy(dest, data, len);
    return(dest);
}

void AddCharStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, char data)
{
    AddToStringTable(memorySubsystem, strtab, &data, sizeof(char), false);
}

char* AddStringStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, char* data)
{
    return(AddToStringTable(memorySubsystem, strtab, data, strlen(data) + 1, false));
}

char* AddBufferStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, void* data, unsigned len)
{
    return(AddToStringTable(memorySubsystem, strtab, data, len, false));
}

char* AddSymbolStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, char* data, unsigned len)
{
    return(AddToStringTable(memorySubsystem, strtab, data, len, true));
}

