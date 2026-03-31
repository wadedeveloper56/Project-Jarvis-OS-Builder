#pragma once

#include <string>
#include <vector>
#include <optional>
#include "SpecifierQualifierList.h"
#include "StructDeclarator.h"

using namespace std;

namespace WadeSpace
{
	class StructDeclaration
	{
		SpecifierQualifierList* specifierQualifierList;
		vector<StructDeclarator*>* vectorStructDeclarator;
	public:
		StructDeclaration() = default;
		StructDeclaration(SpecifierQualifierList* specifierQualifierList, vector<StructDeclarator*>* vectorStructDeclarator);
		virtual ~StructDeclaration() = default;
		StructDeclaration(const StructDeclaration& other) = default;
		StructDeclaration(StructDeclaration&& other) noexcept = default;
		StructDeclaration& operator=(const StructDeclaration& other) = default;
		StructDeclaration& operator=(StructDeclaration&& other) noexcept = default;
		[[nodiscard]] SpecifierQualifierList* getSpecifierQualifierList() const { return specifierQualifierList; }
		[[nodiscard]] vector<StructDeclarator*>* getVectorStructDeclarator() const { return vectorStructDeclarator; }
		void setSpecifierQualifierList(SpecifierQualifierList* specifierQualifierList) { this->specifierQualifierList = specifierQualifierList; }
		void setVectorStructDeclarator(vector<StructDeclarator*>* vectorStructDeclarator) { this->vectorStructDeclarator = vectorStructDeclarator; }
		bool hasSpecifierQualifierList() const { return specifierQualifierList != nullptr; }
		bool hasVectorStructDeclarator() const { return vectorStructDeclarator != nullptr; }
		void addStructDeclarator(StructDeclarator* structDeclarator)
		{
			if (vectorStructDeclarator == nullptr)
			{
				vectorStructDeclarator = new vector<StructDeclarator*>();
			}
			vectorStructDeclarator->push_back(structDeclarator);
		}
	};
}
