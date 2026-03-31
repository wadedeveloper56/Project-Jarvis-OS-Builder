#pragma once

#include <vector>
#include "StructDeclaration.h"

using namespace std;

namespace WadeSpace
{
	class StructOrUnionSpecifier
	{
		CTokenPtr name;
		CTokenPtr structOrUnion;
		vector<StructDeclaration*>* vectorStructDeclaration;
	public:
		StructOrUnionSpecifier() = default;
		StructOrUnionSpecifier(CTokenPtr structOrUnion, CTokenPtr name, vector<StructDeclaration*>* vectorStructDeclaration);
		virtual ~StructOrUnionSpecifier() = default;
		StructOrUnionSpecifier(const StructOrUnionSpecifier& other) = default;
		StructOrUnionSpecifier(StructOrUnionSpecifier&& other) noexcept = default;
		StructOrUnionSpecifier& operator=(const StructOrUnionSpecifier& other) = default;
		StructOrUnionSpecifier& operator=(StructOrUnionSpecifier&& other) noexcept = default;
		[[nodiscard]] CTokenPtr getName() const { return name; }
		[[nodiscard]] CTokenPtr getStructOrUnion() const { return structOrUnion; }
		[[nodiscard]] vector<StructDeclaration*>* getVectorStructDeclaration() const { return vectorStructDeclaration; }
		[[nodiscard]] bool hasName() const { return name != nullptr; }
		[[nodiscard]] bool hasStructOrUnion() const { return structOrUnion != nullptr; }
		[[nodiscard]] bool hasVectorStructDeclaration() const { return vectorStructDeclaration != nullptr; }
		void setName(CTokenPtr name) { this->name = name; }
		void setStructOrUnion(CTokenPtr structOrUnion) { this->structOrUnion = structOrUnion; }
		void setVectorStructDeclaration(vector<StructDeclaration*>* vectorStructDeclaration) { this->vectorStructDeclaration = vectorStructDeclaration; }
		void addStructDeclaration(StructDeclaration* structDeclaration)
		{
			if (vectorStructDeclaration == nullptr)
			{
				vectorStructDeclaration = new vector<StructDeclaration*>();
			}
			vectorStructDeclaration->push_back(structDeclaration);
		}
	};
}
