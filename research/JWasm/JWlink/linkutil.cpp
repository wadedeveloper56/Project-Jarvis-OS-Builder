#include "pch.h"
#include "objstruct.h"
#include "globals.h"
#include "ntio.h"
#include "alloc.h"

static void* SpawnStack;

bool TestBit(byte* array, unsigned num)
{
    byte        mask;

    mask = 1 << (num % 8);
    num /= 8;
    return(*(array + num) & mask);
}

group_entry* FindGroup(segment seg)
{
    group_entry* group;

    for (group = Groups; group != NULL; group = group->next_group) {
        if (group->grp_addr.seg == seg) {
            break;
        }
    }
    return(group);
}

offset FindLinearAddr(targ_addr* addr)
{
    group_entry* group;

    group = FindGroup(addr->seg);
    if (group != NULL) {
        return(addr->off + (group->linear - group->grp_addr.off));
    }
    return(addr->off);
}

offset FindLinearAddr2(targ_addr* addr)
{
    group_entry* group;

    group = FindGroup(addr->seg);
    if (group != NULL) {
        return(addr->off + group->linear + FmtData.base);
    }
    return(addr->off);
}

unsigned_16 blog_32(unsigned_32 value)
{
    unsigned_16 log;

    if (value == 0) {
        return(0);
    }
    log = 31;
    for (; ; ) {
        if (value & 0x80000000) {  // done if high bit on
            break;
        }
        value <<= 1;            // shift left and decrease possible log.
        log--;
    }
    return(log);
}

void Suicide(void)
{
    if (SpawnStack != NULL) {
#ifdef _WIN64
        longjmp((_SETJMP_FLOAT128*)SpawnStack, 1);
#else
        longjmp((int *)SpawnStack, 1);
#endif // _WIN64

    }
}

int Spawn(void (*fn)(void))
{
    void* save_env;
    jmp_buf env;
    int     status;

    save_env = SpawnStack;
    SpawnStack = env;
    status = setjmp(env);
    if (status == 0) {
        (*fn)();
    }
    SpawnStack = save_env;  /* unwind */
    return(status);
}

void WriteStdOut(char* str)
{
    QWrite(_fileno(stdout), str, strlen(str), NULL);
}

void WriteNLStdOut(void)
{
    QWriteNL(_fileno(stdout), NULL);
}

void WriteInfoStdOut(char* str, unsigned level, char* sym)
{
    WriteStdOut(str);
    WriteNLStdOut();
}

void FreeList(void* _curr)
{
    node* curr = (node*)_curr;
    node* next_node;

    while (curr) {
        next_node = (node*)curr->next;
        _LnkFree(curr);
        curr = next_node;
    }
}
