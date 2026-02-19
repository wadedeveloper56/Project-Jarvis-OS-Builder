#pragma once

using namespace std;

namespace WadeSpace
{
	class ProgramData;
	class ExternalDeclaration;
	extern ProgramData *programData;
	extern map<string, ExternalDeclaration*>* typedefList;
	extern bool bit16;
	extern bool bit32;
	extern bool bit64;
	extern char logFileName[_MAX_PATH];
	extern char drive[_MAX_DRIVE];
	extern char dir[_MAX_DIR];
	extern char fname[_MAX_FNAME];
	extern char ext[_MAX_EXT];
}
