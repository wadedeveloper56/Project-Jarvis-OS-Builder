#include <iostream>
#include "DirectDeclarator.h"
#include "ConstantExpression.h"
#include "ParameterTypeList.h"
#include "Declarator.h"

using namespace WadeSpace;
using namespace std;

DirectDeclarator::DirectDeclarator(string& id) : id(id), str1(""), str2(""), directDeclarator(nullptr),
                                                 constantExpression(nullptr), parameterTypeList(nullptr),
                                                 vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator() : id(""), str1(""), str2(""), directDeclarator(nullptr),
                                       constantExpression(nullptr), parameterTypeList(nullptr),
                                       vectorOfStrings(nullptr), declarator(nullptr)
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

DirectDeclarator::DirectDeclarator(string id, Declarator* d) : id(id), str1(""), str2(""),
                                                               directDeclarator(nullptr),
                                                               constantExpression(nullptr), parameterTypeList(nullptr),
                                                               vectorOfStrings(nullptr), declarator(d)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, ConstantExpression* constantExpression) :
	id(""), str1(""), str2(""), directDeclarator(directDeclarator),
	constantExpression(constantExpression),
	parameterTypeList(nullptr), vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, string& str1, string& str2) : id(""),
	str1(str1),
	str2(str2), directDeclarator(directDeclarator), constantExpression(nullptr), parameterTypeList(nullptr),
	vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, ParameterTypeList* parameterTypeList) :
	id(""), str1(""), str2(""), directDeclarator(directDeclarator), constantExpression(nullptr),
	parameterTypeList(parameterTypeList), vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, vector<string>* vectorOfStrings) : id(""),
	str1(""), str2(""),
	directDeclarator(directDeclarator), constantExpression(nullptr), parameterTypeList(nullptr),
	vectorOfStrings(vectorOfStrings),
	declarator(nullptr)
{
}

string DirectDeclarator::getId() const { return id; }
string DirectDeclarator::getStr1() const { return str1; }
string DirectDeclarator::getStr2() const { return str2; }
Declarator* DirectDeclarator::getDeclarator() const { return declarator; }
DirectDeclarator* DirectDeclarator::getDirectDeclarator() const { return directDeclarator; }
ConstantExpression* DirectDeclarator::getConstantExpression() const { return constantExpression; }
ParameterTypeList* DirectDeclarator::getParameterTypeList() const { return parameterTypeList; }
vector<string>* DirectDeclarator::getVectorOfStrings() const { return vectorOfStrings; }
