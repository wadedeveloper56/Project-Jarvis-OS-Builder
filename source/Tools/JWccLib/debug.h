#pragma once

#include "Declaration.h"
#include "Constant.h"
#include "Token.h"
#include "Expression.h"
#include "Pointer.h"
#include "Declaration.h"
#include "DeclarationSpecifiers.h"
#include "Declarator.h"
#include "Token.h"

using namespace std;
using namespace WadeSpace;

Expression* createExpression(
	NodeType type,
	optional<int> token1,
	optional<int> token2,
	Expression* exp1,
	Expression* exp2,
	vector<Expression*>* argumentList,
	optional<string> identifier,
	vector<Initializer*>* initializerList,
	TypeName* typeName,

	Expression* left,
	TokenPtr op,
	Expression* right);
Constant* createConstant(const optional<uint64_t>& iConst, const optional<long double>& fConst, const optional<string>& strConst, const optional<TokenType>& type);
Declarator* createDeclarator(Pointer* pointer, DirectDeclarator* directDeclarator);
DirectDeclarator* createDirectDeclarator(const optional<string>& identifier, const optional<int>& token1, const optional<int>& token2, Declarator* const declarator, DirectDeclarator* const directDeclarator, Expression* const constantExpression, ParameterTypeList* const parameterTypeList, vector<string>* const vectorOfStrings);
DeclarationSpecifiers* createDeclarationSpecifiers(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier, DeclarationSpecifiers* const declarationSpecifiers);
StorageClassSpecifier* createStorageClassSpecifier(const TokenPtr token);
Expression* createPrimaryExpression(const optional<string>& identifier, Constant* constant);
vector<Declaration*>* createDeclarationList(Declaration* exp, vector<Declaration*>* list);

