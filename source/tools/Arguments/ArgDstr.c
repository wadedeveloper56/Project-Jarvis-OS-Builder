#include "pch.h"
#include "framework.h"
#include "ArgumentTable.h"

void arg_dstr_free(arg_dstr_t ds) {
    if (ds->free_proc != NULL) {
        if (ds->free_proc == ARG_DSTR_DYNAMIC) {
            free(ds->data);
        }
        else {
            (*ds->free_proc)(ds->data);
        }
        ds->free_proc = NULL;
    }
}

void setup_append_buf(arg_dstr_t ds, int new_space) {
    int total_space;

    if (ds->data != ds->append_data) {
        if (ds->append_data_size > 500) {
            free(ds->append_data);
            ds->append_data = NULL;
            ds->append_data_size = 0;
        }
        ds->append_used = (int)strlen(ds->data);
    }
    else if (ds->data[ds->append_used] != 0) {
        ds->append_used = (int)strlen(ds->data);
    }

    total_space = new_space + ds->append_used;
    if (total_space >= ds->append_data_size) {
        char* newbuf = NULL;

        if (total_space < 100) {
            total_space = 200;
        }
        else {
            total_space *= 2;
        }
        newbuf = (char*)malloc((unsigned)total_space);
        memset(newbuf, 0, (size_t)total_space);
        strncpy(newbuf, ds->data, (size_t)total_space);   
        assert(newbuf[total_space - 1] == '\0');
        if (ds->append_data != NULL) {
            free(ds->append_data);
        }

        ds->append_data = newbuf;
        ds->append_data_size = total_space;
    }
    else if (ds->data != ds->append_data && ds->append_data != NULL) {
        strncpy(ds->append_data, ds->data, (size_t)ds->append_data_size);   
        assert(ds->append_data[ds->append_data_size - 1] == '\0');
    }

    assert(ds->append_data != NULL);
    arg_dstr_free(ds);
    ds->data = ds->append_data;
}

void arg_dstr_cat(arg_dstr_t ds, const char* str) {
    setup_append_buf(ds, (int)strlen(str) + 1);
    memcpy(ds->data + strlen(ds->data), str, strlen(str));
}

void arg_dstr_catf(arg_dstr_t ds, const char* fmt, ...) {
    va_list arglist;
    char* buff;
    int n, r;
    size_t slen;

    if (fmt == NULL)
        return;

    if ((n = (int)(2 * strlen(fmt))) < START_VSNBUFF)
        n = START_VSNBUFF;

    buff = (char*)malloc((size_t)(n + 2));
    memset(buff, 0, (size_t)(n + 2));

    for (;;) {
        va_start(arglist, fmt);
        r = vsnprintf(buff, (size_t)(n + 1), fmt, arglist);
        va_end(arglist);

        slen = strlen(buff);
        if (slen < (size_t)n)
            break;

        if (r > n)
            n = r;
        else
            n += n;

        free(buff);
        buff = (char*)malloc((size_t)(n + 2));
        memset(buff, 0, (size_t)(n + 2));
    }

    arg_dstr_cat(ds, buff);
    free(buff);
}
