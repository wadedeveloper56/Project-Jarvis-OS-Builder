#pragma once

#include "cansi.tab.h"
#include "ArgumentTable.h"

union ParseUnion {
    int integer;
    char* string;
    long long longlong;
    long double longdouble;
};

void printHeader(void);
void doConversion(void** name);
void initiate(int argc, char* argv[]);
void terminate(int exitCode);

