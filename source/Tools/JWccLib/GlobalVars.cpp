#include "pch.h"

#include "Compiler.h"
#include "Messages.h"
#include "GlobalVars.h"

using namespace std;

namespace WadeSpace
{
	shared_ptr<Compiler> compiler = nullptr;
	Messages messages;
	bool bit16 = false;
	bool bit32 = false;
	bool bit64 = false;
	char logFileName[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
}

