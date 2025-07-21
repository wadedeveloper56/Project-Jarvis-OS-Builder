#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "SpecifierQualifierList.h"
#include "StructDeclarator.h"

using namespace std;

namespace WadeSpace {
	class StructDeclaration
	{
	public:
		StructDeclaration(SpecifierQualifierList* sql, vector<StructDeclarator *>* list);
		StructDeclaration();
		virtual ~StructDeclaration();
	private:
		SpecifierQualifierList* sql;
		vector<StructDeclarator*>* list;
	};
}
