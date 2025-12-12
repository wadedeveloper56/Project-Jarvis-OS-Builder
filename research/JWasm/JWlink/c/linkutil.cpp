#include "pch.h"
#include "globals.h"
#include "linkutil.h"
#include "ntio.h"
#include "mem.h"

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

    for (group = Groups; group != nullptr; group = group->next_group) {
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
    if (group != nullptr) {
        return(addr->off + (group->linear - group->grp_addr.off));
    }
    return(addr->off);
}

offset FindLinearAddr2(targ_addr* addr)
{
    group_entry* group;

    group = FindGroup(addr->seg);
    if (group != nullptr) {
        return(addr->off + group->linear + FmtData.base);
    }
    return(addr->off);
}

bool TestBit(byte* array, unsigned num)
{
    byte        mask;

    mask = 1 << (num % 8);
    num /= 8;
    return(*(array + num) & mask);
}

void WriteStdOut(char* str)
{
    QWrite(_fileno(stdout), str, strlen(str), nullptr);
}

void WriteNLStdOut(void)
{
    QWriteNL(_fileno(stdout), nullptr);
}

void WriteInfoStdOut(char* str, unsigned level, char* sym)
{
    WriteStdOut(str);
    WriteNLStdOut();
}

char* GetEnvString(char* envname)
{
    return(getenv(envname));
}

char* ChkToString(void* mem, unsigned len)
/******************************************/
{
    char* str;

    _ChkAlloc(char *, str, len + 1);
    memcpy(str, mem, len);
    str[len] = '\0';
    return(str);
}

static void* SpawnStack;

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