#pragma once

enum nasm_ctype {
    NCT_NONE = 0x0000,
    NCT_CTRL = 0x0001,
    NCT_SPACE = 0x0002,
    NCT_ASCII = 0x0004,
    NCT_LOWER = 0x0008,    /* isalpha(x) && tolower(x) == x */
    NCT_UPPER = 0x0010,    /* isalpha(x) && tolower(x) != x */
    NCT_DIGIT = 0x0020,
    NCT_HEX = 0x0040,
    NCT_ID = 0x0080,
    NCT_IDSTART = 0x0100,
    NCT_MINUS = 0x0200,    /* - */
    NCT_DOLLAR = 0x0400,    /* $ */
    NCT_UNDER = 0x0800,    /* _ */
    NCT_QUOTE = 0x1000     /* " ' ` */
};
#define SYNC_MAX_SHIFT          31
#define SYNC_MAX_SIZE           (1U << SYNC_MAX_SHIFT)

/* initial # of sync points (*must* be power of two)*/
#define SYNC_INITIAL_CHUNK      (1U << 12)

/*
 * This lot manages the current set of sync points by means of a
 * heap (priority queue) structure.
 */

typedef struct _Sync {
    uint64_t pos;
    uint32_t length;
} Sync;

typedef struct {
    uint32_t field[IF_FIELD_COUNT];
} iflag_t;

void iflag_clear_all(iflag_t* f);
void init_sync(void);
bool nasm_ctype(unsigned char x, enum nasm_ctype mask);
bool nasm_isspace(char x);
bool nasm_isalpha(char x);
bool nasm_isdigit(char x);
bool nasm_isalnum(char x);
bool nasm_isxdigit(char x);
bool nasm_isidstart(char x);
bool nasm_isidchar(char x);
bool nasm_isbrcchar(char x);
bool nasm_isnumstart(char x);
bool nasm_isnumchar(char x);
bool nasm_isquote(char x);
void nasm_ctype_tasm_mode(void);
unsigned int radix_letter(char c);
unsigned int numvalue(unsigned char c);

/* All combinations of instruction flags used in instruction patterns */
extern const iflag_t insns_flags[319];
extern const char* help;
extern unsigned char nasm_tolower_tab[256];
extern uint16_t nasm_ctype_tab[256];
extern Sync* synx;
extern uint32_t max_synx, nsynx;
extern const char nasm_version[];
extern const char nasm_date[];
extern const char nasm_compile_options[];
