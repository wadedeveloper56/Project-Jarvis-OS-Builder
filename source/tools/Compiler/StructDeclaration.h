#pragma once

#include <string>
#include <vector>
#include <stdint.h>
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

	private:
		SpecifierQualifierList* specifierQualifierList;
		vector<StructDeclarator*>* vectorStructDeclarator;
	};
}
