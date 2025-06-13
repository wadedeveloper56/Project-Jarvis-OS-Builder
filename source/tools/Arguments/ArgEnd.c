#include "pch.h"
#include "framework.h"
#include "ArgumentTable.h"

void arg_end_resetfn(void* parent_) {
    ArgEndPtr parent = parent_;
    parent->count = 0;
}

void arg_end_errorfn(void* parent, struct _ArgDstr* ds, int error, const char* argval, const char* progname) {
    (void)parent;

    progname = progname ? progname : "";
    argval = argval ? argval : "";

    arg_dstr_catf(ds, "%s: ", progname);
    switch (error) {
        case ARG_ELIMIT:
            arg_dstr_cat(ds, "too many errors to display");
            break;
        case ARG_EMALLOC:
            arg_dstr_cat(ds, "insufficient memory");
            break;
        case ARG_ENOMATCH:
            arg_dstr_catf(ds, "unexpected argument \"%s\"", argval);
            break;
        case ARG_EMISSARG:
            arg_dstr_catf(ds, "option \"%s\" requires an argument", argval);
            break;
        case ARG_ELONGOPT:
            arg_dstr_catf(ds, "invalid option \"%s\"", argval);
            break;
        default:
            arg_dstr_catf(ds, "invalid option \"-%c\"", error);
            break;
    }

    arg_dstr_cat(ds, "\n");
}

ArgEndPtr arg_end(int maxcount) {
    size_t nbytes;
    ArgEndPtr result;

    nbytes = sizeof(ArgEnd) + (size_t)maxcount * sizeof(int)
        + (size_t)maxcount * sizeof(void*)                            
        + (size_t)maxcount * sizeof(char*);                           

    result = (ArgEndPtr)malloc(nbytes);
    if (result) {
        result->hdr.flag = ARG_TERMINATOR;
        result->hdr.shortopts = NULL;
        result->hdr.longopts = NULL;
        result->hdr.datatype = NULL;
        result->hdr.glossary = NULL;
        result->hdr.mincount = 1;
        result->hdr.maxcount = maxcount;
        result->hdr.parent = result;
        result->hdr.resetfn = arg_end_resetfn;
        result->hdr.scanfn = NULL;
        result->hdr.checkfn = NULL;
        result->hdr.errorfn = arg_end_errorfn;
        result->error = (int*)(result + 1);
        result->parent = (void**)(result->error + maxcount);
        result->argval = (const char**)(result->parent + maxcount);
    }
    return result;
}

void arg_print_errors_ds(struct _ArgDstr* ds, ArgEndPtr end, const char* progname) {
    int i;
    for (i = 0; i < end->count; i++) {
        ArgHdrPtr errorparent = (ArgHdrPtr)(end->parent[i]);
        if (errorparent->errorfn)
            errorparent->errorfn(end->parent[i], ds, end->error[i], end->argval[i], progname);
    }
}

void arg_print_errors(FILE* fp, ArgEndPtr end, const char* progname) {
    struct _ArgDstr* ds = arg_dstr_create();
    arg_print_errors_ds(ds, end, progname);
    fputs(arg_dstr_cstr(ds), fp);
    arg_dstr_destroy(ds);
}
