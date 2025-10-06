#include "Assembler.h"
#include "ArgumentTable.h"

using namespace std;

void iflag_set_all_features(iflag_t* a)
{
    uint32_t* p = &a->field[IF_FEATURE_FIELD];

    memset(p, -1, IF_FEATURE_NFIELDS * sizeof(uint32_t));
}

void iflag_clear(iflag_t* f, unsigned int bit)
{
    f->field[bit >> 5] &= ~IF_GENBIT(bit);
}

bool iflag_test(const iflag_t* f, unsigned int bit)
{
    return !!(f->field[bit >> 5] & IF_GENBIT(bit));
}

void iflag_set(iflag_t* f, unsigned int bit)
{
    f->field[bit >> 5] |= IF_GENBIT(bit);
}

void iflag_set_cpu(iflag_t* a, unsigned int lvl)
{
    a->field[0] = 0;            
    iflag_set_all_features(a);            
    if (lvl >= IF_ANY) {
        iflag_set(a, IF_LATEVEX);
    }
    a->field[IF_CPU_FIELD] &= ~IF_CPU_LEVEL_MASK;
    iflag_set(a, lvl);
}

void set_cpu(const char* value)
{
    char modifier;
    const struct cpunames* cpuflag;
    const struct cpunames cpunames[] = {
        { "default", IF_DEFAULT },     
        { "8086", IF_8086 },
        { "186",  IF_186  },
        { "286",  IF_286  },
        { "386",  IF_386  },
        { "486",  IF_486  },
        { "586",  IF_PENT },
        { "pentium", IF_PENT },
        { "pentiummmx", IF_PENT },
        { "686",  IF_P6 },
        { "p6",   IF_P6 },
        { "ppro", IF_P6 },
        { "pentiumpro", IF_P6 },
        { "p2", IF_P6 },          
        { "pentiumii", IF_P6 },
        { "p3", IF_KATMAI },
        { "katmai", IF_KATMAI },
        { "p4", IF_WILLAMETTE },
        { "willamette", IF_WILLAMETTE },
        { "prescott", IF_PRESCOTT },
        { "x64", IF_X86_64 },
        { "x86-64", IF_X86_64 },
        { "ia64", IF_IA64 },
        { "ia-64", IF_IA64 },
        { "itanium", IF_IA64 },
        { "itanic", IF_IA64 },
        { "merced", IF_IA64 },
        { "nehalem", IF_NEHALEM },
        { "westmere", IF_WESTMERE },
        { "sandybridge", IF_SANDYBRIDGE },
        { "ivybridge", IF_FUTURE },
        { "any", IF_ANY },
        { "all", IF_ANY },
        { "latevex", IF_LATEVEX },
        { "evex", IF_EVEX },
        { "vex", IF_VEX },
        { NULL, 0 }
    };

    if (!value) {
        iflag_set_cpu(&cpu, cpunames[0].level);
        return;
    }

    const char *p = value;
    modifier = '+';
    while (*p) {
        size_t len = strcspn(p, " ,");

        while (len && (*p == '+' || *p == '-' || *p == '*')) {
            modifier = *p++;
            len--;
            if (!len && modifier == '*')
                cpu = cmd_cpu;
        }

        if (len) {
            bool invert_flag = false;

            if (len >= 3 && !nasm_memicmp(p, "no", 2)) {
                invert_flag = true;
                p += 2;
                len -= 2;
            }

            for (cpuflag = cpunames; cpuflag->name; cpuflag++)
                if (!nasm_strnicmp(p, cpuflag->name, len))
                    break;

            if (!cpuflag->name) {
                nasm_nonfatal("unknown CPU type or flag '%.*s'", len, p);
                return;
            }

            if (cpuflag->level >= IF_CPU_FIRST && cpuflag->level <= IF_ANY) {
                iflag_set_cpu(&cpu, cpuflag->level);
            }
            else {
                switch (modifier) {
                    case '-':
                        invert_flag = !invert_flag;
                        break;
                    case '*':
                        invert_flag ^= iflag_test(&cmd_cpu, cpuflag->level);
                        break;
                    default:
                        break;
                }

                iflag_set(&cpu, cpuflag->level);
                if (invert_flag)
                    iflag_clear(&cpu, cpuflag->level);
            }
        }
        p += len;
        if (!*p)
            break;
        p++;                   
    }
}

int64_t make_posix_time(const struct tm* tm)
{
    int64_t t;
    int64_t y = tm->tm_year;

    t = (y - 70) * 365 + (y - 69) / 4 - (y - 1) / 100 + (y + 299) / 400;
    t += tm->tm_yday;
    t *= 24;
    t += tm->tm_hour;
    t *= 60;
    t += tm->tm_min;
    t *= 60;
    t += tm->tm_sec;

    return t;
}

void timestamp(void)
{
    struct compile_time* const oct = &official_compile_time;
    time(&oct->t);
    const struct tm* best_gm = NULL;
    const struct tm* tp = localtime(&oct->t);
    if (tp) {
        oct->local = *tp;
        best_gm = &oct->local;
        oct->have_local = true;
    }

    tp = gmtime(&oct->t);
    if (tp) {
        oct->gm = *tp;
        best_gm = &oct->gm;
        oct->have_gm = true;
        if (!oct->have_local)
            oct->local = oct->gm;
    }
    else {
        oct->gm = oct->local;
    }

    if (best_gm) {
        oct->posix = make_posix_time(best_gm);
        oct->have_posix = true;
    }
}

size_t nasm_get_stack_size_limit(void)
{
    return SIZE_MAX;
}

void set_default_limits(void)
{
    for (int i = 0; i <= LIMIT_MAX; i++)
        nasm_limit[i] = limit_info[i].default_val;
    /*
     * Try to set a sensible default value for the eval depth based
     * on the limit of the stack size, if knowable...
     */
    size_t rl = nasm_get_stack_size_limit();
    int64_t new_limit = rl / (128 * sizeof(void*)); /* Sensible heuristic */
    if (new_limit < nasm_limit[LIMIT_EVAL])
        nasm_limit[LIMIT_EVAL] = new_limit;
}

void ctype_tab_init(void)
{
    int i;

    for (i = 0; i < 256; i++) {
        enum nasm_ctype ct = (enum nasm_ctype)0;

        if (iscntrl(i))
            ct = (enum nasm_ctype)(ct|NCT_CTRL);

        if (isascii(i))
            ct = (enum nasm_ctype)(ct | NCT_ASCII);

        if (isspace(i) && i != '\n')
            ct = (enum nasm_ctype)(ct | NCT_SPACE);

        if (isalpha(i)) {
            ct = (enum nasm_ctype)(ct | ((nasm_tolower(i) == i) ? NCT_LOWER : NCT_UPPER));
            ct = (enum nasm_ctype)(ct | NCT_ID | NCT_IDSTART);
        }

        if (isdigit(i))
            ct = (enum nasm_ctype)(ct | NCT_DIGIT | NCT_ID);

        if (isxdigit(i))
            ct = (enum nasm_ctype)(ct | NCT_HEX);

        /* Non-ASCII character, but no ctype returned (e.g. Unicode) */
        if (!ct && !ispunct(i))
            ct = (enum nasm_ctype)(ct | NCT_ID | NCT_IDSTART);

        nasm_ctype_tab[i] = ct;
    }

    nasm_ctype_tab['-'] |= NCT_MINUS;
    nasm_ctype_tab['$'] |= NCT_DOLLAR | NCT_ID;
    nasm_ctype_tab['_'] |= NCT_UNDER | NCT_ID | NCT_IDSTART;
    nasm_ctype_tab['.'] |= NCT_ID | NCT_IDSTART;
    nasm_ctype_tab['@'] |= NCT_ID | NCT_IDSTART;
    nasm_ctype_tab['?'] |= NCT_ID | NCT_IDSTART;
    nasm_ctype_tab['#'] |= NCT_ID;
    nasm_ctype_tab['~'] |= NCT_ID;
    nasm_ctype_tab['\''] |= NCT_QUOTE;
    nasm_ctype_tab['\"'] |= NCT_QUOTE;
    nasm_ctype_tab['`'] |= NCT_QUOTE;
}

void nasm_ctype_init(void)
{
    tolower_tab_init();
    ctype_tab_init();
}

int ProcessCommandLine(int argc, char* argv[])
{
	return 0;
}

int main(int argc, char* argv[])
{
    error_file = stderr;
    _progname = argv[0];
    if (!_progname || !_progname[0])
        _progname = "assembler";
    timestamp();
    set_cpu(NULL);
    cmd_cpu = cpu;
    set_default_limits();
    include_path = strlist_alloc(true);
    _pass_type = PASS_INIT;
    _passn = 0;
    want_usage = terminate_after_phase = false;
    nasm_ctype_init();
    src_init();
    init_labels();
	ProcessCommandLine(argc, argv);
    cout << "Hello World!\n";
}

