#include "Assembler.h"

void nasm_nonfatal(const char* format, ...) 
{
    va_list args;     
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

fatal_func nasm_critical(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    exit(1);
}