#pragma once

#include <string>
#include <map>
#include <vector>
#include "ProgramData.h"
#include "ExternalDeclaration.h"
#include "StructOrUnionSpecifier.h"
#include "..\Arguments\ArgumentTable.h"

namespace WadeSpace
{
	class Compiler
	{
		ProgramData* programData;

	public:
		Compiler();
		~Compiler();
		void compileFile(istringstream& inStr, ostream& out, int& exitcode);
		void compile(istream& in, ArgFilePtr infiles, ostream& out, int& exitcode);

		[[nodiscard]] ProgramData* getProgramData() const { return programData; }
	};
}
