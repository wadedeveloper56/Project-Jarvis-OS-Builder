#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
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
		string getId() const;
		string getStr1() const;
		string getStr2() const;
		Declarator* getDeclarator() const;
		DirectDeclarator* getDirectDeclarator() const;
		ConstantExpression* getConstantExpression() const;
		ParameterTypeList* getParameterTypeList() const;
		vector<string>* getVectorOfStrings() const;

	private:
		string id;
		string str1;
		string str2;
		Declarator* declarator;
		DirectDeclarator* directDeclarator;
		ConstantExpression* constantExpression;
		ParameterTypeList* parameterTypeList;
		vector<string>* vectorOfStrings;
	};
}
