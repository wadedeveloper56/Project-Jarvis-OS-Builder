#include "pch.h"
#include "linkstd.h"
#include "pcobj.h"
#include "newmem.h"
#include "alloc.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "linkutil.h"
#include "fileio.h"
#include "ring.h"
#include "overlays.h"
#include "strtab.h"
#include "loadfile.h"
#include "permdata.h"
#include "mapio.h"
#include "wressetr.h"

static void* SpawnStack;

int Spawn(void (*fn)(void))
{
    jmp_buf env;

    void *save_env = SpawnStack;
    SpawnStack = env;
    int status = setjmp(env);
    if (status == 0) {
        (*fn)();
    }
    SpawnStack = save_env;  /* unwind */
    return(status);
}

char* GetEnvString(char* envname)
{
    return(getenv(envname));
}

void LnkFatal(char* msg)
{
    LnkMsg(FTL + MSG_INTERNAL, "s", msg);
}

bool TestBit(byte* array, unsigned num)
{
    byte        mask;

    mask = 1 << (num % 8);
    num /= 8;
    return(*(array + num) & mask);
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

void Suicide(void)
{
    if (SpawnStack != NULL) {
        //longjmp((jmp_buf*)SpawnStack, 1);
    }
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
    level = level;
    sym = sym;
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

