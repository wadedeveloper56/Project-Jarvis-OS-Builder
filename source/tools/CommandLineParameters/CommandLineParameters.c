#include "pch.h"
#include "framework.h"
#include "ArgumentTable.h"

void arg_int_resetfn(void* parent_) {
	struct arg_int* parent = parent_;
	parent->count = 0;
}

int arg_int_scanfn(void* parent_, const char* argval) {
	struct arg_int* parent = parent_;
	int errorcode = 0;

	if (parent->count == parent->hdr.maxcount) {
		errorcode = ARG_ERR_MAXCOUNT;
	}
	else if (!argval) {
		parent->count++;
	}
	else {
		long int val;
		const char* end;

		val = strtol0X(argval, &end, 'X', 16);
		if (end == argval) {
			val = strtol0X(argval, &end, 'O', 8);
			if (end == argval) {
				val = strtol0X(argval, &end, 'B', 2);
				if (end == argval) {
					val = strtol(argval, (char**)&end, 10);
					if (end == argval) {
						return ARG_ERR_BADINT;
					}
				}
			}
		}

		if (val > INT_MAX || val < INT_MIN)
			errorcode = ARG_ERR_OVERFLOW;

		if (detectsuffix(end, "KB"))
		{
			if (val > (INT_MAX / 1024) || val < (INT_MIN / 1024))
				errorcode = ARG_ERR_OVERFLOW;
			else
				val *= 1024;
		}
		else if (detectsuffix(end, "MB"))
		{
			if (val > (INT_MAX / 1048576) || val < (INT_MIN / 1048576))
				errorcode = ARG_ERR_OVERFLOW;
			else
				val *= 1048576;
		}
		else if (detectsuffix(end, "GB"))
		{
			if (val > (INT_MAX / 1073741824) || val < (INT_MIN / 1073741824))
				errorcode = ARG_ERR_OVERFLOW;
			else
				val *= 1073741824;
		}
		else if (!detectsuffix(end, ""))
			errorcode = ARG_ERR_BADINT;

		if (errorcode == 0)
			parent->ival[parent->count++] = (int)val;
	}

	return errorcode;
}

int arg_int_checkfn(void* parent_) {
	struct arg_int* parent = parent_;
	int errorcode = (parent->count < parent->hdr.mincount) ? ARG_ERR_MINCOUNT : 0;
	/*printf("%s:checkfn(%p) returns %d\n",__FILE__,parent,errorcode);*/
	return errorcode;
}

void arg_int_errorfn(void* parent_, arg_dstr_t ds, int errorcode, const char* argval, const char* progname) {
	struct arg_int* parent = parent_;
	const char* shortopts = parent->hdr.shortopts;
	const char* longopts = parent->hdr.longopts;
	const char* datatype = parent->hdr.datatype;

	/* make argval NULL safe */
	argval = argval ? argval : "";

	arg_dstr_catf(ds, "%s: ", progname);
	switch (errorcode) {
	case ARG_ERR_MINCOUNT:
		arg_dstr_cat(ds, "missing option ");
		arg_print_option_ds(ds, shortopts, longopts, datatype, "\n");
		break;

	case ARG_ERR_MAXCOUNT:
		arg_dstr_cat(ds, "excess option ");
		arg_print_option_ds(ds, shortopts, longopts, argval, "\n");
		break;

	case ARG_ERR_BADINT:
		arg_dstr_catf(ds, "invalid argument \"%s\" to option ", argval);
		arg_print_option_ds(ds, shortopts, longopts, datatype, "\n");
		break;

	case ARG_ERR_OVERFLOW:
		arg_dstr_cat(ds, "integer overflow at option ");
		arg_print_option_ds(ds, shortopts, longopts, datatype, " ");
		arg_dstr_catf(ds, "(%s is too large)\n", argval);
		break;
	}
}

arg_rem_t* arg_rem(const char* datatype, const char* glossary) { return NULL; }
arg_lit_t* arg_litn(const char* shortopts, const char* longopts, int mincount, int maxcount, const char* glossary) { return NULL; }
arg_lit_t* arg_lit0(const char* shortopts, const char* longopts, const char* glossary) { return NULL; }
arg_lit_t* arg_lit1(const char* shortopts, const char* longopts, const char* glossary) { return NULL; }

arg_int_t* arg_intn(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) {
	size_t nbytes;
	struct arg_int* result;

	maxcount = (maxcount < mincount) ? mincount : maxcount;

	nbytes = sizeof(struct arg_int)
		+ (size_t)maxcount * sizeof(int);

	result = (struct arg_int*)xmalloc(nbytes);

	result->hdr.flag = ARG_HASVALUE;
	result->hdr.shortopts = shortopts;
	result->hdr.longopts = longopts;
	result->hdr.datatype = datatype ? datatype : "<int>";
	result->hdr.glossary = glossary;
	result->hdr.mincount = mincount;
	result->hdr.maxcount = maxcount;
	result->hdr.parent = result;
	result->hdr.resetfn = arg_int_resetfn;
	result->hdr.scanfn = arg_int_scanfn;
	result->hdr.checkfn = arg_int_checkfn;
	result->hdr.errorfn = arg_int_errorfn;
	result->ival = (int*)(result + 1);
	result->count = 0;
	return result;
}

arg_int_t* arg_int0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return arg_intn(shortopts, longopts, datatype, 0, 1, glossary);
}

arg_int_t* arg_int1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return arg_intn(shortopts, longopts, datatype, 1, 1, glossary);
}

arg_dbl_t* arg_dbln(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) { return NULL; }
arg_dbl_t* arg_dbl0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) { return NULL; }
arg_dbl_t* arg_dbl1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) { return NULL; }
arg_str_t* arg_strn(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) { return NULL; }
arg_str_t* arg_str0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) { return NULL; }
arg_str_t* arg_str1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) { return NULL; }
arg_rex_t* arg_rexn(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int mincount, int maxcount, int flags, const char* glossary) { return NULL; }
arg_rex_t* arg_rex0(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int flags, const char* glossary) { return NULL; }
arg_rex_t* arg_rex1(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int flags, const char* glossary) { return NULL; }
arg_file_t* arg_filen(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) { return NULL; }
arg_file_t* arg_file0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) { return NULL; }
arg_file_t* arg_file1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) { return NULL; }
arg_date_t* arg_daten(const char* shortopts, const char* longopts, const char* format, const char* datatype, int mincount, int maxcount, const char* glossary) { return NULL; }
arg_date_t* arg_date0(const char* shortopts, const char* longopts, const char* format, const char* datatype, const char* glossary) { return NULL; }
arg_date_t* arg_date1(const char* shortopts, const char* longopts, const char* format, const char* datatype, const char* glossary) { return NULL; }
arg_end_t* arg_end(int maxcount) { return NULL; }
int arg_nullcheck(void** argtable) { return 0; }
int argParse(int argc, char** argv, void** argtable) { return 0; }
void arg_print_option(FILE* fp, const char* shortopts, const char* longopts, const char* datatype, const char* suffix) {}
void arg_print_syntax(FILE* fp, void** argtable, const char* suffix) {}
void arg_print_glossary(FILE* fp, void** argtable, const char* format) {}
void arg_print_errors(FILE* fp, arg_end_t* end, const char* progname) {}
void arg_print_formatted(FILE* fp, const unsigned lmargin, const unsigned rmargin, const char* text) {}
void arg_freetable(void** argtable, size_t n) {}
