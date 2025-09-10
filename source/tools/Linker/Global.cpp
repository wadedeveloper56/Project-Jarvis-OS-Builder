#include "linker.h"

using namespace std;

char case_sensitive = 1;
char padsegments = 0;
char mapfile = 0;
int output_type = OUTPUT_EXE;
char* outname = 0;
unsigned long imageBase = 0;
unsigned long fileAlign = 1;
unsigned long objectAlign = 1;
unsigned long stackSize;
unsigned long stackCommitSize;
unsigned long heapSize;
unsigned long heapCommitSize;
unsigned char osMajor, osMinor;
unsigned char subsysMajor, subsysMinor;
unsigned int subSystem;
unsigned char* stubName;
vector<string> libraryPath;
unsigned long libPathCount = 0;
vector<string> inputFiles;
unsigned long inputFilesCount = 0;