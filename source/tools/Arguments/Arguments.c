#include "pch.h"
#include "framework.h"
#include "ArgumentTable.h"

ArgRemPtr arg_rem(const char* datatype, const char* glossary) {
	ArgRemPtr result = (ArgRemPtr)malloc(sizeof(ArgRem));
    if (result) {
        result->hdr.flag = 0;
        result->hdr.shortopts = NULL;
        result->hdr.longopts = NULL;
        result->hdr.datatype = datatype;
        result->hdr.glossary = glossary;
        result->hdr.mincount = 1;
        result->hdr.maxcount = 1;
        result->hdr.parent = result;
        result->hdr.resetfn = NULL;
        result->hdr.scanfn = NULL;
        result->hdr.checkfn = NULL;
        result->hdr.errorfn = NULL;
    }
	return result;
}

arg_date_t* arg_daten(const char* shortopts, const char* longopts, const char* format, const char* datatype, int mincount, int maxcount, const char* glossary) {
	return NULL;
}

arg_date_t* arg_date0(const char* shortopts, const char* longopts, const char* format, const char* datatype, const char* glossary) {
	return NULL;
}

arg_date_t* arg_date1(const char* shortopts, const char* longopts, const char* format, const char* datatype, const char* glossary) {
	return NULL;
}

arg_end_t* arg_end(int maxcount) {
	return NULL;
}

int arg_nullcheck(void** argtable) {
	return 0;
}

int argParse(int argc, char** argv, void** argtable) {
	return 0;
}

void arg_print_syntax(FILE* fp, void** argtable, const char* suffix) {
}

void arg_print_glossary(FILE* fp, void** argtable, const char* format) {
}

void arg_print_errors(FILE* fp, arg_end_t* end, const char* progname) {
}

void arg_freetable(void** argtable, size_t n) {
}

void arg_cat(char** pdest, const char* src, size_t* pndest) {
    char* dest = *pdest;
    char* end = dest + *pndest;

    while (dest < end - 1 && *dest != 0)
        dest++;

    while (dest < end - 1 && *src != 0)
        *dest++ = *src++;

    *dest = 0;

    *pndest = (size_t)(end - dest);
    *pdest = dest;
}

void arg_cat_optionv(char* dest, size_t ndest, const char* shortopts, const char* longopts, const char* datatype, int optvalue, const char* separator) {
    separator = separator ? separator : "";

    if (shortopts) {
        const char* c = shortopts;
        while (*c) {
            char shortopt[3];

            shortopt[0] = '-';
            shortopt[1] = *c;
            shortopt[2] = 0;

            arg_cat(&dest, shortopt, &ndest);
            if (*++c)
                arg_cat(&dest, separator, &ndest);
        }
    }

    if (shortopts && longopts)
        arg_cat(&dest, separator, &ndest);

    if (longopts) {
        const char* c = longopts;
        while (*c) {
            size_t ncspn;

            arg_cat(&dest, "--", &ndest);

            ncspn = strcspn(c, ",");
#if (defined(__STDC_LIB_EXT1__) && defined(__STDC_WANT_LIB_EXT1__)) || (defined(__STDC_SECURE_LIB__) && defined(__STDC_WANT_SECURE_LIB__))
            strncat_s(dest, ndest, c, (ncspn < ndest) ? ncspn : ndest);
#else
            strncat(dest, c, (ncspn < ndest) ? ncspn : ndest);
#endif
            c += ncspn;

            if (*c == ',') {
                arg_cat(&dest, separator, &ndest);
                c++;
            }
        }
    }

    if (datatype) {
        if (longopts)
            arg_cat(&dest, "=", &ndest);
        else if (shortopts)
            arg_cat(&dest, " ", &ndest);

        if (optvalue) {
            arg_cat(&dest, "[", &ndest);
            arg_cat(&dest, datatype, &ndest);
            arg_cat(&dest, "]", &ndest);
        }
        else
            arg_cat(&dest, datatype, &ndest);
    }
}

void arg_print_option_ds(arg_dstr_t ds, const char* shortopts, const char* longopts, const char* datatype, const char* suffix) {
	char syntax[200] = "";
	suffix = suffix ? suffix : "";

	arg_cat_optionv(syntax, sizeof(syntax) - 1, shortopts, longopts, datatype, 0, "|");

	arg_dstr_cat(ds, syntax);
	arg_dstr_cat(ds, (char*)suffix);
}
