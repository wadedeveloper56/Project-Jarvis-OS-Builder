#include "pch.h"
#include "linkutil.h"
#include "Structs.h"
#include "MemorySubsystem.h"

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
