
#ifndef ORL_HASH_DEF_INCLUDED
#define ORL_HASH_DEF_INCLUDED

typedef enum {
    ORL_HASH_STRING,
    ORL_HASH_NUMBER
} orl_hash_table_type;

#ifdef __UNIX__
#include <stdint.h>
typedef uintptr_t       orl_hash_value;
#else
typedef uint_32         orl_hash_value;
#endif
typedef uint_32         orl_hash_table_size;
typedef void *          orl_hash_data;

typedef
    int         (*orl_hash_comparison_func)( orl_hash_value, orl_hash_value );

struct orl_hash_data_struct {
    orl_hash_data                       data;
    struct orl_hash_data_struct *       next;
};

typedef struct orl_hash_data_struct orl_hash_data_struct;

struct orl_hash_struct {
    orl_hash_value              key;
    orl_hash_data_struct *      data_struct;
    struct orl_hash_struct *    next;
};

typedef struct orl_hash_struct orl_hash_struct;

struct orl_hash_table_struct {
    orl_hash_table_type         type;
    orl_hash_table_size         size;
    orl_funcs *                 funcs;
    orl_hash_comparison_func    compare;
    orl_hash_struct **          table;
};

typedef struct orl_hash_table_struct orl_hash_table_struct;
typedef orl_hash_table_struct * orl_hash_table;

#endif
