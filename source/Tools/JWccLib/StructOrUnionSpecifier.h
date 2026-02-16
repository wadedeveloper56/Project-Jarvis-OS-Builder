#pragma once

#include <string>
#include <vector>
#include <optional>
#include "StructOrUnion.h"
#include "StructDeclaration.h"

using namespace std;

namespace WadeSpace
{
	class StructOrUnionSpecifier
	{
	public:
		StructOrUnionSpecifier(StructOrUnion* structOrUnion, TokenPtr name, vector<StructDeclaration*>* vectorStructDeclaration);
		StructOrUnionSpecifier(StructOrUnion* structOrUnion, vector<StructDeclaration*>* vectorStructDeclaration);
		StructOrUnionSpecifier(StructOrUnion* structOrUnion, TokenPtr name);
		StructOrUnionSpecifier();
		virtual ~StructOrUnionSpecifier();
		TokenPtr getName() const;
		StructOrUnion* getStructOrUnion() const;
		vector<StructDeclaration*>* getVectorStructDeclaration() const;

	private:
		TokenPtr name;
		StructOrUnion* structOrUnion;
		vector<StructDeclaration*>* vectorStructDeclaration;
	};
}
