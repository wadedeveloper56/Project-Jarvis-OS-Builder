#include "Assembler.h"

FILE* error_file;
const char* _progname;
struct compile_time official_compile_time;
iflag_t cpu, cmd_cpu;
unsigned char nasm_tolower_tab[256];
int64_t nasm_limit[LIMIT_MAX + 1];
const struct limit_info limit_info[LIMIT_MAX + 1] = {
    { "passes", "total number of passes", LIMIT_MAX_VAL },
    { "stalled-passes", "number of passes without forward progress", 1000 },
    { "macro-levels", "levels of macro expansion", 10000 },
    { "macro-tokens", "tokens processed during single-lime macro expansion", 10000000 },
    { "mmacros", "multi-line macros before final return", 100000 },
    { "rep", "%rep count", 1000000 },
    { "eval", "expression evaluation descent", 8192 },
    { "lines", "total source lines processed", 2000000000 }
};
struct strlist* include_path;
enum pass_type _pass_type;
const char* const _pass_types[] =
{
    "init", "preproc-only", "first", "optimize", "stabilize", "final"
};
int64_t _passn;
bool want_usage;
bool terminate_after_phase;
uint16_t nasm_ctype_tab[256];
union label* ldata;              /* all label data blocks */
union label* lfree;              /* labels free block */
struct permts* perm_head;        /* start of perm. text storage */
struct permts* perm_tail;        /* end of perm. text storage */
const char* prevlabel;
bool initialized = false;