#include "pch.h"
#include "framework.h"
#include "ArgumentTable.h"

#define FILESEPARATOR1 '/'
#define FILESEPARATOR2 '/'

void arg_file_resetfn(void* parent_) {
	ArgFilePtr parent = parent_;
	if (parent) parent->count = 0;
}

const char* arg_basename(const char* filename) {
	const char* result = NULL, * result1, * result2;

	result1 = (filename ? strrchr(filename, FILESEPARATOR1) : NULL);
	result2 = (filename ? strrchr(filename, FILESEPARATOR2) : NULL);

	if (result2)
		result = result2 + 1;

	if (result1)
		result = result1 + 1;

	if (!result)
		result = filename;

	if (result && (strcmp(".", result) == 0 || strcmp("..", result) == 0))
		result = filename + strlen(filename);

	return result;
}

const char* arg_extension(const char* basename) {
	const char* result = (basename ? strrchr(basename, '.') : NULL);

	if (basename && !result)
		result = basename + strlen(basename);

	if (basename && result == basename)
		result = basename + strlen(basename);

	if (basename && result && strlen(result) == 1)
		result = basename + strlen(basename);

	return result;
}

int arg_file_scanfn(void* parent_, const char* argval) {
	ArgFilePtr parent = parent_;
	int errorcode = 0;

	if (parent->count == parent->hdr.maxcount) {
		errorcode = ARG_ERR_MAXCOUNT;
	}
	else if (!argval) {
		parent->count++;
	}
	else {
		parent->filename[parent->count] = argval;
		parent->basename[parent->count] = arg_basename(argval);
		parent->extension[parent->count] = arg_extension(parent->basename[parent->count]);
		parent->count++;
	}
	return errorcode;
}

int arg_file_checkfn(void* parent_) {
	ArgFilePtr parent = parent_;
	int errorcode = (parent->count < parent->hdr.mincount) ? ARG_ERR_MINCOUNT : 0;
	return errorcode;
}

void arg_file_errorfn(void* parent_, arg_dstr_t ds, int errorcode, const char* argval, const char* progname) {
	ArgFilePtr parent = parent_;
	const char* shortopts = parent->hdr.shortopts;
	const char* longopts = parent->hdr.longopts;
	const char* datatype = parent->hdr.datatype;

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

		default:
			arg_dstr_catf(ds, "unknown error at \"%s\"\n", argval);
	}
}

ArgFilePtr arg_file0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return arg_filen(shortopts, longopts, datatype, 0, 1, glossary);
}

ArgFilePtr arg_file1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return arg_filen(shortopts, longopts, datatype, 1, 1, glossary);
}

ArgFilePtr arg_filen(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) {
	size_t nbytes;
	ArgFilePtr result;
	int i;

	maxcount = (maxcount < mincount) ? mincount : maxcount;

	nbytes = sizeof(ArgFile)
		+ sizeof(char*) * (size_t)maxcount
		+ sizeof(char*) * (size_t)maxcount
		+ sizeof(char*) * (size_t)maxcount;

	result = (ArgFilePtr)malloc(nbytes);
	if (result) {
		result->hdr.flag = ARG_HASVALUE;
		result->hdr.shortopts = shortopts;
		result->hdr.longopts = longopts;
		result->hdr.glossary = glossary;
		result->hdr.datatype = datatype ? datatype : "<file>";
		result->hdr.mincount = mincount;
		result->hdr.maxcount = maxcount;
		result->hdr.parent = result;
		result->hdr.resetfn = arg_file_resetfn;
		result->hdr.scanfn = arg_file_scanfn;
		result->hdr.checkfn = arg_file_checkfn;
		result->hdr.errorfn = arg_file_errorfn;

		result->filename = (const char**)(result + 1);
		result->basename = result->filename + maxcount;
		result->extension = result->basename + maxcount;
		result->count = 0;

		for (i = 0; i < maxcount; i++) {
			result->filename[i] = "";
			result->basename[i] = "";
			result->extension[i] = "";
		}
	}
	return result;
}
