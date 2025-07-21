#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

using namespace std;

namespace WadeSpace {
	class ConstantExpression;
	class ParameterTypeList;
	class Declarator;

	class DirectDeclarator
	{
	public:
		DirectDeclarator(string id);
		DirectDeclarator(string id, Declarator* declarator);
		DirectDeclarator(DirectDeclarator* directDeclarator, string str1, string str2);
		DirectDeclarator(DirectDeclarator* directDeclarator, ConstantExpression* constantExpression);
		DirectDeclarator(DirectDeclarator* directDeclarator, ParameterTypeList* parameterTypeList);
		DirectDeclarator(DirectDeclarator* directDeclarator, vector<string>* vs);
		DirectDeclarator();
		virtual ~DirectDeclarator();
		bool hasDeclarator() const;
		Declarator* getDeclarator() const;
	public:
		string id;
		string str1;
		string str2;
		Declarator* declarator;
		DirectDeclarator* directDeclarator;
		ConstantExpression* constantExpression;
		ParameterTypeList* parameterTypeList;
		vector<string>* vs;
	};
}
