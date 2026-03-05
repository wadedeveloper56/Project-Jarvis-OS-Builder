#pragma once

#include <vector>
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

		StructOrUnionSpecifier(const StructOrUnionSpecifier& other);
		StructOrUnionSpecifier(StructOrUnionSpecifier&& other) noexcept;
		StructOrUnionSpecifier& operator=(const StructOrUnionSpecifier& other);
		StructOrUnionSpecifier& operator=(StructOrUnionSpecifier&& other) noexcept;

		[[nodiscard]] TokenPtr getName() const;
		[[nodiscard]] TokenPtr getStructOrUnion() const;
		[[nodiscard]] vector<StructDeclaration*>* getVectorStructDeclaration() const;

		[[nodiscard]] bool hasName() const;
		[[nodiscard]] bool hasStructOrUnion() const;
		[[nodiscard]] bool hasVectorStructDeclaration() const;

	private:
		TokenPtr name;
		TokenPtr structOrUnion;
		vector<StructDeclaration*>* vectorStructDeclaration;
	};
}
