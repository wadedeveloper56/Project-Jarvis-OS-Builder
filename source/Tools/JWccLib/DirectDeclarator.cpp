#include "pch.h"
#include "DirectDeclarator.h"
#include "ParameterTypeList.h"
#include "Declarator.h"
#include "ExpressionTree.h"

using namespace WadeSpace;
using namespace std;

DirectDeclarator::DirectDeclarator(
	CTokenPtr identifier,
	CTokenPtr token1,
	CTokenPtr token2,
	Declarator* const declarator,
	DirectDeclarator* const directDeclarator,
	ExpressionTree* const constantExpression,
	ParameterTypeList* const parameterTypeList,
	vector<CTokenPtr>* const vectorOfStrings)
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

DirectDeclarator::~DirectDeclarator()
{
	delete declarator;
	delete directDeclarator;
	delete constantExpression;
	delete parameterTypeList;
	delete identifier;
	delete token1;
	delete token2;
	if (vectorOfStrings != nullptr)
	{
		for (auto CToken : *vectorOfStrings)
		{
			delete CToken;
		}
		delete vectorOfStrings;
	}
}

CTokenPtr DirectDeclarator::getIdentifier() const
{
	return identifier;
}

CTokenPtr DirectDeclarator::getToken1() const
{
	return token1;
}

CTokenPtr DirectDeclarator::getToken2() const
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

ExpressionTree* DirectDeclarator::getConstantExpression() const
{
	return constantExpression;
}

ParameterTypeList* DirectDeclarator::getParameterTypeList() const
{
	return parameterTypeList;
}

vector<CTokenPtr>* DirectDeclarator::getVectorOfStrings() const
{
	return vectorOfStrings;
}

DirectDeclarator::DirectDeclarator(const DirectDeclarator& other)
{
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	token1 = other.token1 ? new CToken(*other.token1) : nullptr;
	token2 = other.token2 ? new CToken(*other.token2) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
	parameterTypeList = other.parameterTypeList ? new ParameterTypeList(*other.parameterTypeList) : nullptr;
	vectorOfStrings = other.vectorOfStrings ? new vector<CTokenPtr>(*other.vectorOfStrings) : nullptr;
}

DirectDeclarator::DirectDeclarator(DirectDeclarator&& other) noexcept
{
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	token1 = other.token1 ? new CToken(*other.token1) : nullptr;
	token2 = other.token2 ? new CToken(*other.token2) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
	parameterTypeList = other.parameterTypeList ? new ParameterTypeList(*other.parameterTypeList) : nullptr;
	vectorOfStrings = other.vectorOfStrings ? new vector<CTokenPtr>(*other.vectorOfStrings) : nullptr;
}

DirectDeclarator& DirectDeclarator::operator=(const DirectDeclarator& other)
{
	if (this == &other)
		return *this;
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	token1 = other.token1 ? new CToken(*other.token1) : nullptr;
	token2 = other.token2 ? new CToken(*other.token2) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
	parameterTypeList = other.parameterTypeList ? new ParameterTypeList(*other.parameterTypeList) : nullptr;
	vectorOfStrings = other.vectorOfStrings ? new vector<CTokenPtr>(*other.vectorOfStrings) : nullptr;
	return *this;
}

DirectDeclarator& DirectDeclarator::operator=(DirectDeclarator&& other) noexcept
{
	if (this == &other)
		return *this;
	identifier = other.identifier ? new CToken(*other.identifier) : nullptr;
	token1 = other.token1 ? new CToken(*other.token1) : nullptr;
	token2 = other.token2 ? new CToken(*other.token2) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	constantExpression = other.constantExpression ? new ExpressionTree(*other.constantExpression) : nullptr;
	parameterTypeList = other.parameterTypeList ? new ParameterTypeList(*other.parameterTypeList) : nullptr;
	vectorOfStrings = other.vectorOfStrings ? new vector<CTokenPtr>(*other.vectorOfStrings) : nullptr;
	return *this;
}

