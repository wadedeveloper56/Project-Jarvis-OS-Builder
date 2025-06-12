#include "pch.h"
#include "framework.h"
#include "ArgumentTable.h"

void arg_int_resetfn(void* parent_) {
	ArgIntPtr parent = (ArgIntPtr)parent_;
	parent->count = 0;
}

long int strtol0X(const char* str, const char** endptr, char X, int base) {
	long int val;
	int s = 1;
	const char* ptr = str;

	while (isspace((int)(*ptr)))
		ptr++;
	switch (*ptr) {
	case '+':
		ptr++;
		s = 1;
		break;
	case '-':
		ptr++;
		s = -1;
		break;
	default:
		s = 1;
		break;
	}
	if ((*ptr++) != '0') {
		*endptr = str;
		return 0;
	}
	if (toupper(*ptr++) != toupper(X)) {
		*endptr = str;
		return 0;
	}
	val = strtol(ptr, (char**)endptr, base);
	if (*endptr == ptr) {
		*endptr = str;
		return 0;
	}

	return s * val;
}

int detectsuffix(const char* str, const char* suffix) {
	while (toupper(*str) == toupper(*suffix)) {
		if (*str == '\0')
			return 1;

		str++;
		suffix++;
	}
	if (*suffix != 0)
		return 0;

	while (isspace((int)(*str)))
		str++;

	return (*str == '\0') ? 1 : 0;
}

int arg_int_scanfn(void* parent_, const char* argval) {
	ArgIntPtr parent = (ArgIntPtr)parent_;
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
	ArgIntPtr parent = (ArgIntPtr)parent_;
	int errorcode = (parent->count < parent->hdr.mincount) ? ARG_ERR_MINCOUNT : 0;
	return errorcode;
}

void arg_int_errorfn(void* parent_, struct _ArgDstr* ds, int errorcode, const char* argval, const char* progname) {
	ArgIntPtr parent = (ArgIntPtr)parent_;
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

ArgIntPtr arg_intn(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) {
	size_t nbytes;
	ArgIntPtr result;

	maxcount = (maxcount < mincount) ? mincount : maxcount;

	nbytes = sizeof(ArgInt) + (size_t)maxcount * sizeof(int);

	result = (ArgIntPtr)malloc(nbytes);
	if (result) {
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
	}
	return result;
}

ArgIntPtr arg_int0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return arg_intn(shortopts, longopts, datatype, 0, 1, glossary);
}

ArgIntPtr arg_int1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return arg_intn(shortopts, longopts, datatype, 1, 1, glossary);
}
