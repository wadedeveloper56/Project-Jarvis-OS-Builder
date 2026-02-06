#include "pch.h"
#include "DirectDeclarator.h"
#include "ParameterTypeList.h"
#include "Declarator.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

DirectDeclarator::DirectDeclarator(const optional<string>& identifier, const optional<int>& token1, const optional<int>& str2,
	Declarator* const declarator, DirectDeclarator* const directDeclarator,
	Expression* const constantExpression, ParameterTypeList* const parameterTypeList,
	vector<string>* const vectorOfStrings)
	: identifier(identifier),
	token1(token1),
	token2(str2),
	declarator(declarator),
	directDeclarator(directDeclarator),
	constantExpression(constantExpression),
	parameterTypeList(parameterTypeList),
	vectorOfStrings(vectorOfStrings)
{
}

optional<string> DirectDeclarator::getIdentifier() const
{
	return identifier;
}

optional<int> DirectDeclarator::getToken1() const
{
	return token1;
}

optional<int> DirectDeclarator::getToken2() const
{
	return token2;
}

Declarator* DirectDeclarator::getDeclarator() const
{
	return declarator;
}

DirectDeclarator* DirectDeclarator::getDirectDeclarator() const
{
	return directDeclarator;
}

Expression* DirectDeclarator::getConstantExpression() const
{
	return constantExpression;
}

ParameterTypeList* DirectDeclarator::getParameterTypeList() const
{
	return parameterTypeList;
}

vector<string>* DirectDeclarator::getVectorOfStrings() const
{
	return vectorOfStrings;
}
