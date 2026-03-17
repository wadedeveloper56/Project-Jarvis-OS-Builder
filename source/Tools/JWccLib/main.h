#pragma once

#include <iostream>
#include "../Arguments/ArgumentTable.h"
#include "../Preprocessor/simplecpp.h"
using namespace std;
void compileFile(istringstream& inStr, ostream& out, int& exitcode);
void compile(istream& in, ArgFilePtr infiles, ostream& out, int& exitcode);
