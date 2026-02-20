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
	: identifier(new Token(*other.identifier)),
	token1(new Token(*other.token1)),
	token2(new Token(*other.token2)),
	declarator(new Declarator(*other.declarator)),
	directDeclarator(new DirectDeclarator(*other.directDeclarator)),
	constantExpression(new Expression(*other.constantExpression)),
	parameterTypeList(new ParameterTypeList(*other.parameterTypeList)),
	vectorOfStrings(new vector<TokenPtr>(*other.vectorOfStrings))
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator&& other) noexcept
	: identifier(new Token(*other.identifier)),
	token1(new Token(*other.token1)),
	token2(new Token(*other.token2)),
	declarator(new Declarator(*other.declarator)),
	directDeclarator(new DirectDeclarator(*other.directDeclarator)),
	constantExpression(new Expression(*other.constantExpression)),
	parameterTypeList(new ParameterTypeList(*other.parameterTypeList)),
	vectorOfStrings(new vector<TokenPtr>(*other.vectorOfStrings))
{
}

DirectDeclarator& DirectDeclarator::operator=(const DirectDeclarator& other)
{
	if (this == &other)
		return *this;
	identifier = new Token(*other.identifier);
	token1 = new Token(*other.token1);
	token2 = new Token(*other.token2);
	declarator = new Declarator(*other.declarator);
	directDeclarator = new DirectDeclarator(*other.directDeclarator);
	constantExpression = new Expression(*other.constantExpression);
	parameterTypeList = new ParameterTypeList(*other.parameterTypeList);
	vectorOfStrings = new vector<TokenPtr>(*other.vectorOfStrings);
	return *this;
}

DirectDeclarator& DirectDeclarator::operator=(DirectDeclarator&& other) noexcept
{
	if (this == &other)
		return *this;
	identifier = new Token(*other.identifier);
	token1 = new Token(*other.token1);
	token2 = new Token(*other.token2);
	declarator = new Declarator(*other.declarator);
	directDeclarator = new DirectDeclarator(*other.directDeclarator);
	constantExpression = new Expression(*other.constantExpression);
	parameterTypeList = new ParameterTypeList(*other.parameterTypeList);
	vectorOfStrings = new vector<TokenPtr>(*other.vectorOfStrings);
	return *this;
}

