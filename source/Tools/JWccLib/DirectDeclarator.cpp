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
	vector<TokenPtr>* const vectorOfStrings)
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
		for (auto token : *vectorOfStrings)
		{
			delete token;
		}
		delete vectorOfStrings;
	}
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

vector<TokenPtr>* DirectDeclarator::getVectorOfStrings() const
{
	return vectorOfStrings;
}

DirectDeclarator::DirectDeclarator(const DirectDeclarator& other)
{
	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
	token1 = other.token1 ? new Token(*other.token1) : nullptr;
	token2 = other.token2 ? new Token(*other.token2) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
	parameterTypeList = other.parameterTypeList ? new ParameterTypeList(*other.parameterTypeList) : nullptr;
	vectorOfStrings = other.vectorOfStrings ? new vector<TokenPtr>(*other.vectorOfStrings) : nullptr;
}

DirectDeclarator::DirectDeclarator(DirectDeclarator&& other) noexcept
{
	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
	token1 = other.token1 ? new Token(*other.token1) : nullptr;
	token2 = other.token2 ? new Token(*other.token2) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
	parameterTypeList = other.parameterTypeList ? new ParameterTypeList(*other.parameterTypeList) : nullptr;
	vectorOfStrings = other.vectorOfStrings ? new vector<TokenPtr>(*other.vectorOfStrings) : nullptr;
}

DirectDeclarator& DirectDeclarator::operator=(const DirectDeclarator& other)
{
	if (this == &other)
		return *this;
	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
	token1 = other.token1 ? new Token(*other.token1) : nullptr;
	token2 = other.token2 ? new Token(*other.token2) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
	parameterTypeList = other.parameterTypeList ? new ParameterTypeList(*other.parameterTypeList) : nullptr;
	vectorOfStrings = other.vectorOfStrings ? new vector<TokenPtr>(*other.vectorOfStrings) : nullptr;
	return *this;
}

DirectDeclarator& DirectDeclarator::operator=(DirectDeclarator&& other) noexcept
{
	if (this == &other)
		return *this;
	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
	token1 = other.token1 ? new Token(*other.token1) : nullptr;
	token2 = other.token2 ? new Token(*other.token2) : nullptr;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	directDeclarator = other.directDeclarator ? new DirectDeclarator(*other.directDeclarator) : nullptr;
	constantExpression = other.constantExpression ? new Expression(*other.constantExpression) : nullptr;
	parameterTypeList = other.parameterTypeList ? new ParameterTypeList(*other.parameterTypeList) : nullptr;
	vectorOfStrings = other.vectorOfStrings ? new vector<TokenPtr>(*other.vectorOfStrings) : nullptr;
	return *this;
}

