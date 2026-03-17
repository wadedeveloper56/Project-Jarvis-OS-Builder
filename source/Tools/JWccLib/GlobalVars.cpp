#include "pch.h"
#include "ProgramData.h"
#include "Compile.h"

using namespace std;

namespace WadeSpace
{
	Compile compile;
	bool bit16 = false;
	bool bit32 = false;
	bool bit64 = false;
	char logFileName[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
}
