#include "pch.h"
#include "globals.h"
#include "memalloc.h"
#include "parser.h"
#include "macro.h"
#include "input.h"
#include "lqueue.h"
#include "myassert.h"

#define INC_PATH_DELIM      ';'
#define INC_PATH_DELIM_STR  ";"
#define DIR_SEPARATOR       '\\'
#define filecmp _stricmp
#define ISPC( x ) ( x == '/' || x == '\\' || x == ':' )
#define ISABS( x ) ( *x == '/' || *x == '\\' || ( *x &&  *(x+1) == ':' && ( *(x+2) == '/' || *(x+2) == '\\' ) ) )

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

const char* GetFNamePart(const char* fname)
{
    const char* rc;
    for (rc = fname; *fname; fname++)
        if (ISPC(*fname))
            rc = fname + 1;
    return(rc);
}

void print_source_nesting_structure(void)
{
}

void UpdateLineNumber(struct asym* sym, void* p)
{
    struct src_item* curr;
    for (curr=src_stack; curr; curr=curr->next)
        if (curr->type == SIT_FILE) {
            sym->value=curr->line_num;
            break;
        }
    return;
}

uint_32 GetLineNumber(void)
{
    UpdateLineNumber(LineCur, NULL);
    return(LineCur->uvalue);
}

#ifdef DEBUG_OUT
static unsigned lqlines_written;       
static unsigned lqlines_read;          

unsigned GetLqLine(void) { return(lqlines_read); }

char* GetTopLine(char* buffer)
{
    *buffer=NULLC;
    if (ModuleInfo.GeneratedCode)
        sprintf(buffer, "(%u)", GetLqLine());
    else if (src_stack->type == SIT_MACRO)
        sprintf(buffer, "[%s.%" I32_SPEC "u]", src_stack->mi->macro->name, src_stack->line_num);
    return(buffer);
}
#endif