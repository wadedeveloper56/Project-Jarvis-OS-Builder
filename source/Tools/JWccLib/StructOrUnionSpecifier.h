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
		StructOrUnionSpecifier(TokenPtr structOrUnion, TokenPtr name, vector<StructDeclaration*>* vectorStructDeclaration);
		StructOrUnionSpecifier(TokenPtr structOrUnion, vector<StructDeclaration*>* vectorStructDeclaration);
		StructOrUnionSpecifier(TokenPtr structOrUnion, TokenPtr name);
		StructOrUnionSpecifier();
		virtual ~StructOrUnionSpecifier();
		TokenPtr getName() const;
		TokenPtr getStructOrUnion() const;
		vector<StructDeclaration*>* getVectorStructDeclaration() const;

	private:
		TokenPtr name;
		TokenPtr structOrUnion;
		vector<StructDeclaration*>* vectorStructDeclaration;
	};
}
