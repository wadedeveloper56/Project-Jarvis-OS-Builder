#pragma once

#include "ProgramData.h"

using namespace WadeSpace;
using namespace std;

namespace WadeSpace {
	extern ProgramData programData;
	extern bool bit16;
	extern bool bit32;
	extern bool bit64;
	extern char logFileName[_MAX_PATH];
	extern char drive[_MAX_DRIVE];
	extern char dir[_MAX_DIR];
	extern char fname[_MAX_FNAME];
	extern char ext[_MAX_EXT];
}