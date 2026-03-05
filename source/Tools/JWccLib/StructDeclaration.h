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
	public:
		StructDeclaration();
		StructDeclaration(SpecifierQualifierList* specifierQualifierList, vector<StructDeclarator*>* vectorStructDeclarator);
		virtual ~StructDeclaration();

		StructDeclaration(const StructDeclaration& other);
		StructDeclaration(StructDeclaration&& other) noexcept;
		StructDeclaration& operator=(const StructDeclaration& other);
		StructDeclaration& operator=(StructDeclaration&& other) noexcept;

		[[nodiscard]] SpecifierQualifierList* getSpecifierQualifierList() const;
		[[nodiscard]] vector<StructDeclarator*>* getVectorStructDeclarator() const;

		[[nodiscard]] bool hasSpecifierQualifierList() const;
		[[nodiscard]] bool hasVectorStructDeclarator() const;

	private:
		SpecifierQualifierList* specifierQualifierList;
		vector<StructDeclarator*>* vectorStructDeclarator;
	};
}
