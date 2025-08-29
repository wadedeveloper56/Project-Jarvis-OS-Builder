#include "pch.h"
#include "simplecpp.h"

using namespace simplecpp;
using namespace std;

Output::Output(const vector<string>& files) : type(ERROR0), location(files) {}
Output::Output(const vector<string>& files, Type type, const string& msg) : type(type), location(files), msg(msg) {}
