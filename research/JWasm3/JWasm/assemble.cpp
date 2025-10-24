#include "pch.h"
#include "globals.h"
#include "assemble.h"

struct module_info      ModuleInfo;
jmp_buf jmpenv;
bool write_to_file;
unsigned int            Parse_Pass;

int EXPQUAL AssembleModule(const char* source)
{
	return 0;
}

void close_files(void)
{
}