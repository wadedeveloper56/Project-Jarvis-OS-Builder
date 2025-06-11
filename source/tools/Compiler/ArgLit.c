#include "pch.h"
#include "framework.h"
#include "ArgumentTable.h"

void arg_lit_resetfn(void* parent_) {
	ArgLitPtr parent = (ArgLitPtr)parent_;
	parent->count = 0;
}

int arg_lit_scanfn(void* parent_, const char* argval) {
	ArgLitPtr parent = parent_;
	int errorcode = 0;
	if (parent->count < parent->hdr.maxcount)
		parent->count++;
	else
		errorcode = ARG_ERR_MAXCOUNT;
	return errorcode;
}

int arg_lit_checkfn(void* parent_) {
	ArgLitPtr parent = parent_;
	int errorcode = (parent->count < parent->hdr.mincount) ? ARG_ERR_MINCOUNT : 0;
	return errorcode;
}

void arg_lit_errorfn(void* parent_, arg_dstr_t ds, int errorcode, const char* argval, const char* progname) {
	ArgLitPtr parent = parent_;
	const char* shortopts = parent->hdr.shortopts;
	const char* longopts = parent->hdr.longopts;
	const char* datatype = parent->hdr.datatype;

	switch (errorcode) {
	case ARG_ERR_MINCOUNT:
		arg_dstr_catf(ds, "%s: missing option ", progname);
		arg_print_option_ds(ds, shortopts, longopts, datatype, "\n");
		arg_dstr_cat(ds, "\n");
		break;

	case ARG_ERR_MAXCOUNT:
		arg_dstr_catf(ds, "%s: extraneous option ", progname);
		arg_print_option_ds(ds, shortopts, longopts, datatype, "\n");
		break;
	}
}

ArgLitPtr arg_litn(const char* shortopts, const char* longopts, int mincount, int maxcount, const char* glossary) {
	ArgLitPtr result;

	maxcount = (maxcount < mincount) ? mincount : maxcount;

	result = (ArgLitPtr)malloc(sizeof(ArgLit));
	if (result) {
		result->hdr.flag = 0;
		result->hdr.shortopts = shortopts;
		result->hdr.longopts = longopts;
		result->hdr.datatype = NULL;
		result->hdr.glossary = glossary;
		result->hdr.mincount = mincount;
		result->hdr.maxcount = maxcount;
		result->hdr.parent = result;
		result->hdr.resetfn = arg_lit_resetfn;
		result->hdr.scanfn = arg_lit_scanfn;
		result->hdr.checkfn = arg_lit_checkfn;
		result->hdr.errorfn = arg_lit_errorfn;
		result->count = 0;
	}
	return result;
}

ArgLitPtr arg_lit0(const char* shortopts, const char* longopts, const char* glossary) {
	return arg_litn(shortopts, longopts, 0, 1, glossary);
}

ArgLitPtr arg_lit1(const char* shortopts, const char* longopts, const char* glossary) {
	return arg_litn(shortopts, longopts, 1, 1, glossary);
}
