#include "DirectDeclarator.h"

using namespace WadeSpace;
using namespace std;

DirectDeclarator::DirectDeclarator(string id) :id(id), str1(""), str2(""), directDeclarator(NULL), constantExpression(NULL), parameterTypeList(NULL), vectorOfStrings(NULL), declarator(NULL) {}
DirectDeclarator::DirectDeclarator() :id(""), str1(""), str2(""), directDeclarator(NULL), constantExpression(NULL), parameterTypeList(NULL), vectorOfStrings(NULL), declarator(NULL) {}
DirectDeclarator::~DirectDeclarator() {}
DirectDeclarator::DirectDeclarator(string id, Declarator* d) :id(""), str1(""), str2(""), directDeclarator(directDeclarator), constantExpression(NULL), parameterTypeList(NULL), vectorOfStrings(NULL), declarator(d) {}
DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, ConstantExpression* constantExpression) :id(""), str1(""), str2(""), directDeclarator(directDeclarator), constantExpression(constantExpression), parameterTypeList(NULL), vectorOfStrings(NULL), declarator(NULL) {}
DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, string str1, string str2) :id(""), str1(str1), str2(str2), directDeclarator(directDeclarator), constantExpression(NULL), parameterTypeList(NULL), vectorOfStrings(NULL), declarator(NULL) {}
DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, ParameterTypeList* parameterTypeList) :id(""), str1(""), str2(""), directDeclarator(directDeclarator), constantExpression(NULL), parameterTypeList(parameterTypeList), vectorOfStrings(NULL), declarator(NULL) {}
DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, vector<string>* vs) :id(""), str1(""), str2(""), directDeclarator(directDeclarator), constantExpression(NULL), parameterTypeList(NULL), vectorOfStrings(vs), declarator(NULL) {}
bool DirectDeclarator::hasDeclarator() const { return declarator; }
bool DirectDeclarator::hasDirectDeclarator() const { return directDeclarator; }
bool DirectDeclarator::hasConstantExpression() const { return constantExpression; }
bool DirectDeclarator::hasParameterTypeList() const { return parameterTypeList; }
bool DirectDeclarator::hasVectorOfStrings() const { return vectorOfStrings; }
string DirectDeclarator::getId() const { return id; }
string DirectDeclarator::getStr1() const { return str1; }
string DirectDeclarator::getStr2() const { return str2; }
Declarator* DirectDeclarator::getDeclarator() const { return declarator; }
DirectDeclarator* DirectDeclarator::getDirectDeclarator() const { return directDeclarator; }
ConstantExpression* DirectDeclarator::getConstantExpression() const { return constantExpression; }
ParameterTypeList* DirectDeclarator::getParameterTypeList() const { return parameterTypeList; }
vector<string>* DirectDeclarator::getVectorOfStrings() const { return vectorOfStrings; }
