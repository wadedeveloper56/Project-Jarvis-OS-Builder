#include "pch.h"
#include "linker.h"
#include "LinkerMemory.h"

using namespace std;

LinkerMemory memory;
Parameters parameters;
vector<string> libraryPath;
unsigned long libPathCount = 0;
vector<string> inputFiles;
unsigned long inputFilesCount = 0;