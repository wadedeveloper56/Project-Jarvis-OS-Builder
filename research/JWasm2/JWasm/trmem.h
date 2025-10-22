#ifndef _TRMEM_H_INCLUDED
#define _TRMEM_H_INCLUDED

#include <stddef.h>

typedef struct _trmem_internal *_trmem_hdl;

typedef void (*_trmem_who)( void );       
#define _TRMEM_NO_ROUTINE   ((_trmem_who)0)

typedef void *(*_trmem_realloc_who)(void*,size_t);
#define _TRMEM_NO_REALLOC ((_trmem_realloc_who)0)

enum {
    _TRMEM_ALLOC_SIZE_0     =0x0001,      
    _TRMEM_REALLOC_SIZE_0   =0x0002,      
    _TRMEM_REALLOC_NULL     =0x0004,       
    _TRMEM_FREE_NULL        =0x0008,       
    _TRMEM_OUT_OF_MEMORY    =0x0010,      
    _TRMEM_CLOSE_CHECK_FREE =0x0020      
};

_trmem_hdl _trmem_open(
    void *(*__alloc)(size_t),
    void (*__free)(void*),
    void * (*__realloc)(void*,size_t),
    void * (*__expand)(void*,size_t),
    FILE *__prt_parm,
    void (*__prt_line)( FILE *__prt_parm, const char *__buf, size_t __len ),
    unsigned __flags
);


unsigned _trmem_close( _trmem_hdl );


void *_trmem_alloc( size_t, _trmem_who, _trmem_hdl );
void _trmem_free( void *, _trmem_who, _trmem_hdl );
void *_trmem_realloc( void *, size_t, _trmem_who, _trmem_hdl );
void *_trmem_expand( void *, size_t, _trmem_who, _trmem_hdl );
char *_trmem_strdup( const char *str, _trmem_who who, _trmem_hdl hdl );
size_t _trmem_msize( void *, _trmem_hdl );


void _trmem_prt_usage( _trmem_hdl );
unsigned _trmem_prt_list( _trmem_hdl );

unsigned long _trmem_get_current_usage( _trmem_hdl );
unsigned long _trmem_get_peak_usage( _trmem_hdl );

_trmem_who  _trmem_guess_who( void * );
#ifdef __WATCOMC__
#pragma aux _trmem_guess_who = \
    0x8b 0x45 0x04           \
    parm caller         [] \
    value               [eax] \
    modify exact        [eax];
#endif

#endif
