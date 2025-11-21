#include <iostream>
#include "DirectDeclarator.h"
#include "ParameterTypeList.h"
#include "Declarator.h"
#include "ExpressionNode.h"

using namespace WadeSpace;
using namespace std;

DirectDeclarator::DirectDeclarator(string id) : identifier(id), str1(nullopt), str2(nullopt), directDeclarator(nullptr),
constantExpression(nullptr), parameterTypeList(nullptr),
vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator() : identifier(nullopt), str1(nullopt), str2(nullopt), directDeclarator(nullptr),
constantExpression(nullptr), parameterTypeList(nullptr),
vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator(string id, Declarator* d) : identifier(id), str1(nullopt), str2(nullopt),
directDeclarator(nullptr),
constantExpression(nullptr), parameterTypeList(nullptr),
vectorOfStrings(nullptr), declarator(d)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, ExpressionNode* constantExpression) :
	identifier(nullopt), str1(nullopt), str2(nullopt), directDeclarator(directDeclarator),
	constantExpression(constantExpression),
	parameterTypeList(nullptr), vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, int& str1, int& str2) : identifier(nullopt),
str1(str1),
str2(str2), directDeclarator(directDeclarator), constantExpression(nullptr), parameterTypeList(nullptr),
vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, ParameterTypeList* parameterTypeList) :
	identifier(nullopt), str1(nullopt), str2(nullopt), directDeclarator(directDeclarator), constantExpression(nullptr),
	parameterTypeList(parameterTypeList), vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, vector<string>* vectorOfStrings) : identifier(nullopt),
str1(nullopt), str2(nullopt),
directDeclarator(directDeclarator), constantExpression(nullptr), parameterTypeList(nullptr),
vectorOfStrings(vectorOfStrings),
declarator(nullptr)
{
}

DirectDeclarator::~DirectDeclarator()
{
	delete declarator;
	delete directDeclarator;
	delete constantExpression;
	delete parameterTypeList;
	delete vectorOfStrings;
}

optional<string> DirectDeclarator::getIdentifier() const { return identifier; }
optional<int> DirectDeclarator::getStr1() const { return str1; }
optional<int> DirectDeclarator::getStr2() const { return str2; }
Declarator* DirectDeclarator::getDeclarator() const { return declarator; }
DirectDeclarator* DirectDeclarator::getDirectDeclarator() const { return directDeclarator; }
ExpressionNode* DirectDeclarator::getConstantExpression() const { return constantExpression; }
ParameterTypeList* DirectDeclarator::getParameterTypeList() const { return parameterTypeList; }
vector<string>* DirectDeclarator::getVectorOfStrings() const { return vectorOfStrings; }
