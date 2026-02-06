#pragma once

#include "Declaration.h"
#include "Constant.h"

using namespace std;
using namespace WadeSpace;

Declarator* createDeclarator(Pointer* pointer, DirectDeclarator* directDeclarator);
DirectDeclarator* createDirectDeclarator(const optional<string>& identifier, const optional<int>& token1, const optional<int>& token2, Declarator* const declarator, DirectDeclarator* const directDeclarator, Expression* const constantExpression, ParameterTypeList* const parameterTypeList, vector<string>* const vectorOfStrings);
DeclarationSpecifiers* createDeclarationSpecifiers(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier, DeclarationSpecifiers* const declarationSpecifiers);
StorageClassSpecifier* createStorageClassSpecifier(const int& value, const TokenType type);
Expression* createPrimaryExpression(const optional<string>& identifier, Constant* constant);
vector<Declaration*>* createDeclarationList(Declaration* exp, vector<Declaration*>* list);

