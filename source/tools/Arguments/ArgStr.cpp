#include "pch.h"
#include "framework.h"
#include "ArgumentTable.h"

void arg_str_resetfn(void* parent_) {
	ArgStrPtr parent = (ArgStrPtr)parent_;
	int i;

	for (i = 0; i < parent->count; i++) {
		parent->sval[i] = "";
	}
	parent->count = 0;
}

int arg_str_scanfn(void* parent_, const char* argval) {
	ArgStrPtr parent = (ArgStrPtr)parent_;
	int errorcode = 0;

	if (parent->count == parent->hdr.maxcount) {
		errorcode = ARG_ERR_MAXCOUNT;
	}
	else if (!argval) {
		parent->count++;
	}
	else {
		parent->sval[parent->count++] = argval;
	}

	return errorcode;
}

int arg_str_checkfn(void* parent_) {
	ArgStrPtr parent = (ArgStrPtr)parent_;
	int errorcode = (parent->count < parent->hdr.mincount) ? ARG_ERR_MINCOUNT : 0;
	return errorcode;
}

void arg_str_errorfn(void* parent_, struct _ArgDstr* ds, int errorcode, const char* argval, const char* progname) {
	ArgStrPtr parent = (ArgStrPtr)parent_;
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
	}
}

ArgStrPtr arg_str0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return arg_strn(shortopts, longopts, datatype, 0, 1, glossary);
}

ArgStrPtr arg_str1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return arg_strn(shortopts, longopts, datatype, 1, 1, glossary);
}

ArgStrPtr arg_strn(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) {
	size_t nbytes;
	ArgStrPtr result;
	int i;

	maxcount = (maxcount < mincount) ? mincount : maxcount;

	nbytes = sizeof(ArgStr) + (size_t)maxcount * sizeof(char*);

	result = (ArgStrPtr)malloc(nbytes);
	if (result) {
		result->hdr.flag = ARG_HASVALUE;
		result->hdr.shortopts = shortopts;
		result->hdr.longopts = longopts;
		result->hdr.datatype = datatype ? datatype : "<string>";
		result->hdr.glossary = glossary;
		result->hdr.mincount = mincount;
		result->hdr.maxcount = maxcount;
		result->hdr.parent = result;
		result->hdr.resetfn = arg_str_resetfn;
		result->hdr.scanfn = arg_str_scanfn;
		result->hdr.checkfn = arg_str_checkfn;
		result->hdr.errorfn = arg_str_errorfn;

		result->sval = (const char**)(result + 1);
		result->count = 0;

		for (i = 0; i < maxcount; i++) {
			result->sval[i] = "";
		}
	}
	return result;
}
