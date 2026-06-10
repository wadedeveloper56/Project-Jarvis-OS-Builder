
#ifndef ORL_COMMON_INCLUDED
#define ORL_COMMON_INCLUDED

typedef struct {
    orl_sec_handle                      section;
    orl_sec_offset                      offset;
    orl_symbol_handle                   symbol;
    orl_reloc_type                      type;
    union {
        orl_reloc_addend                addend;
        orl_reloc_addend_signed         addend_signed;
    };
    orl_symbol_handle                   frame;        
} orl_reloc;

typedef
    orl_return          (*orl_sec_return_func)( orl_sec_handle );

typedef
    orl_return          (*orl_reloc_return_func)( orl_reloc * );

typedef
    orl_return          (*orl_symbol_return_func)( orl_symbol_handle );

typedef
    orl_return          (*orl_group_return_func)( orl_group_handle );

typedef struct {
    orl_return  (*lnk_cmd_fn)( char *, char *, void * );
    orl_return  (*scantab_fn)( orl_sec_handle, orl_sec_offset, orl_sec_offset,
                                void * );
} orl_note_callbacks;

#endif
