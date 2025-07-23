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
		DirectDeclarator(string& id);
		DirectDeclarator(string id, Declarator* declarator);
		DirectDeclarator(DirectDeclarator* directDeclarator, string& str1, string& str2);
		DirectDeclarator(DirectDeclarator* directDeclarator, ConstantExpression* constantExpression);
		DirectDeclarator(DirectDeclarator* directDeclarator, ParameterTypeList* parameterTypeList);
		DirectDeclarator(DirectDeclarator* directDeclarator, vector<string>* vectorOfStrings);
		DirectDeclarator();
		virtual ~DirectDeclarator();
		bool hasId() const;
		bool hasStr1() const;
		bool hasStr2() const;
		string getId() const;
		string getStr1() const;
		string getStr2() const;
		Declarator* getDeclarator() const;
		DirectDeclarator* getDirectDeclarator() const;
		ConstantExpression* getConstantExpression() const;
		ParameterTypeList* getParameterTypeList() const;
		vector<string>* getVectorOfStrings() const;

	private:
		optional<reference_wrapper<string>> id;
		optional<reference_wrapper<string>> str1;
		optional<reference_wrapper<string>> str2;
		Declarator* declarator;
		DirectDeclarator* directDeclarator;
		ConstantExpression* constantExpression;
		ParameterTypeList* parameterTypeList;
		vector<string>* vectorOfStrings;
	};
}
