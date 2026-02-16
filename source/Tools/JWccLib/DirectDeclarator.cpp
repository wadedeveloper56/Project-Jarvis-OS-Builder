#include "pch.h"
#include "DirectDeclarator.h"
#include "ParameterTypeList.h"
#include "Declarator.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

DirectDeclarator::DirectDeclarator(
	TokenPtr identifier, 
	TokenPtr token1,
	TokenPtr token2,
	Declarator* const declarator, 
	DirectDeclarator* const directDeclarator,
	Expression* const constantExpression,
	ParameterTypeList* const parameterTypeList,
	vector<string>* const vectorOfStrings)
	: identifier(identifier),
	token1(token1),
	token2(token2),
	declarator(declarator),
	directDeclarator(directDeclarator),
	constantExpression(constantExpression),
	parameterTypeList(parameterTypeList),
	vectorOfStrings(vectorOfStrings)
{
}

TokenPtr DirectDeclarator::getIdentifier() const
{
	return identifier;
}

TokenPtr DirectDeclarator::getToken1() const
{
	return token1;
}

TokenPtr DirectDeclarator::getToken2() const
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
