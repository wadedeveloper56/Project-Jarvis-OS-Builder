#include "pch.h"
#include "objstruct.h"
#include "globals.h"

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

void WriteStdOut(char* str)
{
    //QWrite(STDOUT_HANDLE, str, strlen(str), NULL);
}

void WriteNLStdOut(void)
{
    //QWriteNL(STDOUT_HANDLE, NULL);
}