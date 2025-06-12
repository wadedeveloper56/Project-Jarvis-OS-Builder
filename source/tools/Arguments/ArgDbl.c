#include "pch.h"
#include "framework.h"
#include "ArgumentTable.h"

void arg_dbl_resetfn(void* parent_) {
	ArgDblPtr parent = (ArgDblPtr)parent_;
	if (parent) parent->count = 0;
}

int arg_dbl_scanfn(void* parent_, const char* argval) {
	ArgDblPtr parent = (ArgDblPtr)parent_;
	int errorcode = 0;

	if (parent->count == parent->hdr.maxcount) {
		errorcode = ARG_ERR_MAXCOUNT;
	}
	else if (!argval) {
		parent->count++;
	}
	else {
		double val;
		char* end;

		val = strtod(argval, &end);

		if (*end == 0)
			parent->dval[parent->count++] = val;
		else
			errorcode = ARG_ERR_BADDOUBLE;
	}

	return errorcode;
}

int arg_dbl_checkfn(void* parent_) {
	ArgDblPtr parent = (ArgDblPtr)parent_;
	int errorcode = (parent->count < parent->hdr.mincount) ? ARG_ERR_MINCOUNT : 0;
	return errorcode;
}

void arg_dbl_errorfn(void* parent_, arg_dstr_t ds, int errorcode, const char* argval, const char* progname) {
	ArgDblPtr parent = (ArgDblPtr)parent_;
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

	case ARG_ERR_BADDOUBLE:
		arg_dstr_catf(ds, "invalid argument \"%s\" to option ", argval);
		arg_print_option_ds(ds, shortopts, longopts, datatype, "\n");
		break;
	}
}

ArgDblPtr arg_dbl0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return arg_dbln(shortopts, longopts, datatype, 0, 1, glossary);
}

ArgDblPtr arg_dbl1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return arg_dbln(shortopts, longopts, datatype, 1, 1, glossary);
}

ArgDblPtr arg_dbln(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) {
	size_t nbytes;
	ArgDblPtr result;
	size_t addr;
	size_t rem;

	maxcount = (maxcount < mincount) ? mincount : maxcount;

	nbytes = sizeof(ArgDbl)	+ (size_t)(maxcount + 1) * sizeof(double);

	result = (ArgDblPtr)malloc(nbytes);
	if (result) {
		result->hdr.flag = ARG_HASVALUE;
		result->hdr.shortopts = shortopts;
		result->hdr.longopts = longopts;
		result->hdr.datatype = datatype ? datatype : "<double>";
		result->hdr.glossary = glossary;
		result->hdr.mincount = mincount;
		result->hdr.maxcount = maxcount;
		result->hdr.parent = result;
		result->hdr.resetfn = arg_dbl_resetfn;
		result->hdr.scanfn = arg_dbl_scanfn;
		result->hdr.checkfn = arg_dbl_checkfn;
		result->hdr.errorfn = arg_dbl_errorfn;

		addr = (size_t)(result + 1);
		rem = addr % sizeof(double);
		result->dval = (double*)(addr + sizeof(double) - rem);
		result->count = 0;
	}
	return result;
}
