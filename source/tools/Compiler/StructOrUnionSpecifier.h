#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "StructOrUnion.h"
#include "StructDeclaration.h"

using namespace std;

namespace WadeSpace {
	class StructOrUnionSpecifier
	{
	public:
		StructOrUnionSpecifier(StructOrUnion* su, string name, vector<StructDeclaration *>* list);
		StructOrUnionSpecifier(StructOrUnion* su, vector<StructDeclaration *>* list);
		StructOrUnionSpecifier(StructOrUnion* su, string name);
		StructOrUnionSpecifier();
		virtual ~StructOrUnionSpecifier();
	private:
		string name;
		StructOrUnion* su;
		vector<StructDeclaration *>* list;
	};
}
