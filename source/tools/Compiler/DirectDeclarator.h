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
	class ExpressionNode;

	class DirectDeclarator
	{
	public:
		DirectDeclarator(string id);
		DirectDeclarator(string id, Declarator* declarator);
		DirectDeclarator(DirectDeclarator* directDeclarator, int& str1, int& str2);
		DirectDeclarator(DirectDeclarator* directDeclarator, ExpressionNode* constantExpression);
		DirectDeclarator(DirectDeclarator* directDeclarator, ParameterTypeList* parameterTypeList);
		DirectDeclarator(DirectDeclarator* directDeclarator, vector<string>* vectorOfStrings);
		DirectDeclarator();
		virtual ~DirectDeclarator();
		optional<string> getIdentifier() const;
		optional<int> getStr1() const;
		optional<int> getStr2() const;
		Declarator* getDeclarator() const;
		DirectDeclarator* getDirectDeclarator() const;
		ExpressionNode* getConstantExpression() const;
		ParameterTypeList* getParameterTypeList() const;
		vector<string>* getVectorOfStrings() const;

	private:
		optional<string> identifier;
		optional<int> str1;
		optional<int> str2;
		Declarator* declarator;
		DirectDeclarator* directDeclarator;
		ExpressionNode* constantExpression;
		ParameterTypeList* parameterTypeList;
		vector<string>* vectorOfStrings;
	};
}
