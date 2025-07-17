#include "DirectDeclarator.h"

using namespace WadeSpace;
using namespace std;

DirectDeclarator::DirectDeclarator(string id) :id(id), str1(""), str2(""), directDeclarator(NULL), constantExpression(NULL), parameterTypeList(NULL), vs(NULL), declarator(NULL) {}
DirectDeclarator::DirectDeclarator() :id(""), str1(""), str2(""), directDeclarator(NULL), constantExpression(NULL), parameterTypeList(NULL), vs(NULL), declarator(NULL) {}
DirectDeclarator::~DirectDeclarator() {}
DirectDeclarator::DirectDeclarator(string id, Declarator* d) :id(""), str1(""), str2(""), directDeclarator(directDeclarator), constantExpression(NULL), parameterTypeList(NULL), vs(NULL), declarator(d) {}
DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, ConstantExpression* constantExpression) :id(""), str1(""), str2(""), directDeclarator(directDeclarator), constantExpression(constantExpression), parameterTypeList(NULL), vs(NULL), declarator(NULL) {}
DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, string str1, string str2) :id(""), str1(str1), str2(str2), directDeclarator(directDeclarator), constantExpression(NULL), parameterTypeList(NULL), vs(NULL), declarator(NULL) {}
DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, ParameterTypeList* parameterTypeList) :id(""), str1(""), str2(""), directDeclarator(directDeclarator), constantExpression(NULL), parameterTypeList(parameterTypeList), vs(NULL), declarator(NULL) {}
DirectDeclarator::DirectDeclarator(DirectDeclarator* directDeclarator, vector<string>* vs) :id(""), str1(""), str2(""), directDeclarator(directDeclarator), constantExpression(NULL), parameterTypeList(NULL), vs(vs), declarator(NULL) {}
bool DirectDeclarator::hasDeclarator() const { return declarator; }
Declarator* DirectDeclarator::getDeclarator() const { return declarator; }
