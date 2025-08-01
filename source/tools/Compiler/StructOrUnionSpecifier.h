#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "StructOrUnion.h"
#include "StructDeclaration.h"

using namespace std;

namespace WadeSpace
{
	class StructOrUnionSpecifier
	{
	public:
		StructOrUnionSpecifier(StructOrUnion* structOrUnion, const string& name, vector<StructDeclaration*>* vectorStructDeclaration);
		StructOrUnionSpecifier(StructOrUnion* structOrUnion, vector<StructDeclaration*>* vectorStructDeclaration);
		StructOrUnionSpecifier(StructOrUnion* structOrUnion, const string& name);
		StructOrUnionSpecifier();
		virtual ~StructOrUnionSpecifier();
		optional<string> getName() const;
		StructOrUnion* getStructOrUnion() const;
		vector<StructDeclaration*>* getVectorStructDeclaration() const;

	private:
		optional<string> name;
		StructOrUnion* structOrUnion;
		vector<StructDeclaration*>* vectorStructDeclaration;
	};
}
