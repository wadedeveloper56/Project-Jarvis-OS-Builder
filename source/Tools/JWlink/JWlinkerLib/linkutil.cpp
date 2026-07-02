#include "pch.h"
#include "linkutil.h"
#include "Structs.h"
#include "MemorySubsystem.h"
#include "globals.h"
#include "ntio.h"

using namespace std;

void FreeList(MemorySubsystem *memorySubsystem, void* _curr)
{
    node* curr = (node*)_curr;
    node* next_node;

    while (curr)
    {
        next_node = (node*)curr->next;
        memorySubsystem->FreeMemory(curr);
        curr = next_node;
    }
}

void LinkList(void* in_head, void* newnode)
{
    node** owner;

    owner = (node**)&in_head;
    ((node*)newnode)->next = NULL;
    while (*owner != NULL)
    {
        owner = (node**)&(*owner)->next;
    }
    *owner = (node*)newnode;
}

char* ChkStrDup(MemorySubsystem *memorySubsystem,char* str)
{
    size_t      len;
    char* copy;

    len = strlen(str) + 1;
    _LnkAlloc(char *,copy, len);
    memcpy(copy, str, len);
    return(copy);
}

char* ChkToString(MemorySubsystem *memorySubsystem, void* mem, unsigned len)
{
    char* str;

    _LnkAlloc(char *,str, len + 1);
    memcpy(str, mem, len);
    str[len] = '\0';
    return(str);
}

uint16_t blog_32(uint32_t value)
{
    uint16_t log;

    if (value == 0)
    {
        return(0);
    }
    log = 31;
    for (; ; )
    {
        if (value & 0x80000000)
        {       
            break;
        }
        value <<= 1;                  
        log--;
    }
    return(log);
}

group_entry* FindGroup(segment seg)
{
    group_entry* group;

    for (group = Groups; group != NULL; group = group->next_group)
    {
        if (group->grp_addr.seg == seg)
        {
            break;
        }
    }
    return(group);
}

offset FindLinearAddr(targ_addr* addr)
{
    group_entry* group;

    group = FindGroup(addr->seg);
    if (group != NULL)
    {
        return(addr->off + (group->linear - group->grp_addr.off));
    }
    return(addr->off);
}

offset FindLinearAddr2(targ_addr* addr)
{
    group_entry* group;

    group = FindGroup(addr->seg);
    if (group != NULL)
    {
        return(addr->off + group->linear + FmtData.base);
    }
    return(addr->off);
}

void WriteStdOut(char* str)
{
    QWrite(STDOUT_HANDLE, str, strlen(str), NULL);
}

void WriteNLStdOut(void)
{
    QWriteNL(STDOUT_HANDLE, NULL);
}

void WriteInfoStdOut(char* str, unsigned level, char* sym)
{
    WriteStdOut(str);
    WriteNLStdOut();
}
