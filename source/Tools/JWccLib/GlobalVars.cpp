#include "pch.h"
#include "ProgramData.h"

using namespace std;

namespace WadeSpace
{
	ProgramData *programData = nullptr;
	map<string,ExternalDeclaration*>* typedefList = nullptr;
	map<string, StructOrUnionSpecifier*>* structList = nullptr;
	vector<string>* functionList = nullptr;
	bool bit16 = false;
	bool bit32 = false;
	bool bit64 = false;
	char logFileName[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
}
