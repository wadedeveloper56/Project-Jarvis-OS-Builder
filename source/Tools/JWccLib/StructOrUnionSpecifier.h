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
		StructOrUnionSpecifier();
		StructOrUnionSpecifier(TokenPtr structOrUnion, TokenPtr name, vector<StructDeclaration*>* vectorStructDeclaration);
		virtual ~StructOrUnionSpecifier();

		TokenPtr getName() const;
		TokenPtr getStructOrUnion() const;
		vector<StructDeclaration*>* getVectorStructDeclaration() const;

		StructOrUnionSpecifier(const StructOrUnionSpecifier& other);
		StructOrUnionSpecifier(StructOrUnionSpecifier&& other) noexcept;
		StructOrUnionSpecifier& operator=(const StructOrUnionSpecifier& other);
		StructOrUnionSpecifier& operator=(StructOrUnionSpecifier&& other) noexcept;

	private:
		TokenPtr name;
		TokenPtr structOrUnion;
		vector<StructDeclaration*>* vectorStructDeclaration;
	};
}
