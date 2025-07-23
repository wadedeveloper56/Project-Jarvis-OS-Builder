#include "DirectDeclarator.h"
#include "ConstantExpression.h"
#include "ParameterTypeList.h"
#include "Declarator.h"

using namespace WadeSpace;
using namespace std;

DirectDeclarator::DirectDeclarator(string& id) : id(id), str1(nullopt), str2(nullopt), directDeclarator(nullptr),
                                                 constantExpression(nullptr), parameterTypeList(nullptr),
                                                 vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator() : id(nullopt), str1(nullopt), str2(nullopt), directDeclarator(nullptr),
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

DirectDeclarator::DirectDeclarator(string id, Declarator* d) : id(id), str1(nullopt), str2(nullopt),
                                                               directDeclarator(nullptr),
                                                               constantExpression(nullptr), parameterTypeList(nullptr),
                                                               vectorOfStrings(nullptr), declarator(d)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, ConstantExpression* constantExpression) :
	id(nullopt), str1(nullopt), str2(nullopt), directDeclarator(directDeclarator),
	constantExpression(constantExpression),
	parameterTypeList(nullptr), vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, string& str1, string& str2) : id(nullopt),
	str1(str1),
	str2(str2), directDeclarator(directDeclarator), constantExpression(nullptr), parameterTypeList(nullptr),
	vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, ParameterTypeList* parameterTypeList) :
	id(nullopt), str1(nullopt), str2(nullopt), directDeclarator(directDeclarator), constantExpression(nullptr),
	parameterTypeList(parameterTypeList), vectorOfStrings(nullptr), declarator(nullptr)
{
}

DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, vector<string>* vectorOfStrings) : id(nullopt),
	str1(nullopt), str2(nullopt),
	directDeclarator(directDeclarator), constantExpression(nullptr), parameterTypeList(nullptr),
	vectorOfStrings(vectorOfStrings),
	declarator(nullptr)
{
}

bool DirectDeclarator::hasId() const { return id.has_value(); }
bool DirectDeclarator::hasStr1() const { return str1.has_value(); }
bool DirectDeclarator::hasStr2() const { return str2.has_value(); }
string DirectDeclarator::getId() const { return id.value(); }
string DirectDeclarator::getStr1() const { return str1.value(); }
string DirectDeclarator::getStr2() const { return str2.value(); }
Declarator* DirectDeclarator::getDeclarator() const { return declarator; }
DirectDeclarator* DirectDeclarator::getDirectDeclarator() const { return directDeclarator; }
ConstantExpression* DirectDeclarator::getConstantExpression() const { return constantExpression; }
ParameterTypeList* DirectDeclarator::getParameterTypeList() const { return parameterTypeList; }
vector<string>* DirectDeclarator::getVectorOfStrings() const { return vectorOfStrings; }
