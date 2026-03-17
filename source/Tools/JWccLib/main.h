#pragma once

#include <iostream>
#include "ArgumentTable.h"
using namespace std;
void compileFile(istringstream& inStr, ostream& out, int& exitcode);
void compile(istream& in, ArgFilePtr infiles, ostream& out, int& exitcode);
