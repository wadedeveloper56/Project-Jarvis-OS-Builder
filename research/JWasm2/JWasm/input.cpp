#include "pch.h"
#include "globals.h"
#include "memalloc.h"
#include "parser.h"
#include "macro.h"
#include "input.h"
#include "lqueue.h"
#include "myassert.h"

struct asym* FileCur;       
struct asym* LineCur;          

enum src_item_type {
    SIT_FILE,
    SIT_MACRO,
};

struct src_item {
    struct src_item* next;
    uint_8              type;               
    uint_16             srcfile;          
    union {
        void* content;     
        FILE* file;            
        struct macro_instance* mi;        
    };
    uint_32             line_num;       
};

static struct src_item* SrcFree;

#define src_stack  ModuleInfo.g.src_stack
int GetCurrSrcPos(char* buffer)
{
    struct src_item* curr;

    for (curr = src_stack; curr; curr = curr->next) {
        if (curr->type == SIT_FILE) {
            return(sprintf(buffer, ModuleInfo.EndDirFound == FALSE ? "%s(%" I32_SPEC "u) : " : "%s : ", GetFName(curr->srcfile)->fname, curr->line_num));
        }
    }
    *buffer = NULLC;
    return(0);
}

const struct fname_item* GetFName(unsigned index)
{
    return NULL;
}

void print_source_nesting_structure(void)
{
}