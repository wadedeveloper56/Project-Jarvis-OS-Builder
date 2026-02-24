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
		StructDeclaration(SpecifierQualifierList* specifierQualifierList, vector<StructDeclarator*>* vectorStructDeclarator);
		StructDeclaration();
		virtual ~StructDeclaration();
		SpecifierQualifierList* getSpecifierQualifierList() const;
		vector<StructDeclarator*>* getVectorStructDeclarator() const;
		StructDeclaration(const StructDeclaration& other);
		StructDeclaration(StructDeclaration&& other) noexcept;
		StructDeclaration& operator=(const StructDeclaration& other);
		StructDeclaration& operator=(StructDeclaration&& other) noexcept;

	private:
		SpecifierQualifierList* specifierQualifierList;
		vector<StructDeclarator*>* vectorStructDeclarator;
	};
}
