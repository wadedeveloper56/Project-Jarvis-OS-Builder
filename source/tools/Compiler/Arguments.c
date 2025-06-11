// Arguments.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "ArgumentTable.h"

arg_rem_t* arg_rem(const char* datatype, const char* glossary) {
	return NULL;
}

arg_lit_t* arg_litn(const char* shortopts, const char* longopts, int mincount, int maxcount, const char* glossary) {
	return NULL;
}

arg_lit_t* arg_lit0(const char* shortopts, const char* longopts, const char* glossary) {
	return NULL;
}

arg_lit_t* arg_lit1(const char* shortopts, const char* longopts, const char* glossary) {
	return NULL;
}

arg_int_t* arg_intn(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) {
	return NULL;
}

arg_int_t* arg_int0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return NULL;
}

arg_int_t* arg_int1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return NULL;
}

arg_dbl_t* arg_dbln(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) {
	return NULL;
}

arg_dbl_t* arg_dbl0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return NULL;
}

arg_dbl_t* arg_dbl1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return NULL;
}

arg_str_t* arg_strn(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) {
	return NULL;
}

arg_str_t* arg_str0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return NULL;
}

arg_str_t* arg_str1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return NULL;
}

arg_rex_t* arg_rexn(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int mincount, int maxcount, int flags, const char* glossary) {
	return NULL;
}

arg_rex_t* arg_rex0(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int flags, const char* glossary) {
	return NULL;
}

arg_rex_t* arg_rex1(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int flags, const char* glossary) {
	return NULL;
}

arg_file_t* arg_filen(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary) {
	return NULL;
}

arg_file_t* arg_file0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return NULL;
}

arg_file_t* arg_file1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary) {
	return NULL;
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

