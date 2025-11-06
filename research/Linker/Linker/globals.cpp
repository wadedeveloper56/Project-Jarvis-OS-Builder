#include "pch.h"
#include "globals.h"

using namespace std;

stateflag  LinkState;
nodearray* ExtNodes;           // ptr to obj file import list
nodearray* SegNodes;           // ptr to obj file segment list
nodearray* GrpNodes;           // ptr to obj file group list
nodearray* NameNodes;          // ptr to obj file lname list
char* TokBuff;                 // Multi-purpose large buffer
unsigned TokSize;
char* TFileName;
unsigned long    TmpFSize;
fstream* TempFile;
symbol** GlobalSymPtrs;
symbol** StaticSymPtrs;
readcache* ReadCacheList;
