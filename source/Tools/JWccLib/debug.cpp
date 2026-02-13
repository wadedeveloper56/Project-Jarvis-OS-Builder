#include "pch.h"
#include "debug.h"
#include "Expression.h"

using namespace std;
using namespace WadeSpace;

vector<InitDeclarator*>* createInitDeclaratorList(InitDeclarator* value1, vector<InitDeclarator*>* list)
{
	if (list == nullptr)
	{
		list = new vector<InitDeclarator*>();
	}
	list->push_back(value1);
	return list;
}

vector<Expression*>* createArgumentExpressionList(Expression* exp, vector<Expression*>* list)
{
	if (list == nullptr)
	{
		list = new vector<Expression*>();
	}
	list->push_back(exp);
	return list;
}

Expression* createExpression(
	NodeType type,
	optional<int> token1,
	optional<int> token2,
	Expression* const lexp,
	Expression* exp1,
	Expression* exp2,
	vector<Expression*>* argumentList,
	optional<string> identifier,
	vector<Initializer*>* initializerList,
	TypeName* typeName,
	TokenPtr token3,
	Expression* left,
	TokenPtr op,
	Expression* right)
{
	return new Expression(new NodeData(type, token1, token2, lexp, exp1, exp2, argumentList, identifier, initializerList, typeName, token3), left, op, right);
}

Constant* createConstant(const optional<uint64_t>& iConst, const optional<long double>& fConst, const optional<string>& strConst, const optional<TokenType>& type)
{
	return new Constant(iConst, fConst, strConst, type);
}

Declarator* createDeclarator(Pointer* pointer, DirectDeclarator* directDeclarator)
{
	return new Declarator(pointer, directDeclarator);
}

DirectDeclarator* createDirectDeclarator(const optional<string>& identifier, const optional<int>& token1, const optional<int>& token2, Declarator* const declarator, DirectDeclarator* const directDeclarator, Expression* const constantExpression, ParameterTypeList* const parameterTypeList, vector<string>* const vectorOfStrings)
{
	return new DirectDeclarator(identifier, token1, token2, declarator, directDeclarator, constantExpression, parameterTypeList, vectorOfStrings);
}

DeclarationSpecifiers* createDeclarationSpecifiers(StorageClassSpecifier* const storageClassSpecifier, TypeSpecifier* const typeSpecifier, TypeQualifier* const typeQualifier, DeclarationSpecifiers* const declarationSpecifiers)
{
	return new DeclarationSpecifiers(storageClassSpecifier, typeSpecifier, typeQualifier, declarationSpecifiers);
}

StorageClassSpecifier* createStorageClassSpecifier(const TokenPtr token)
{
	return new StorageClassSpecifier(token);
}

Expression* createPrimaryExpression(const optional<string>& identifier, Constant* constant)
{
	return new Expression();//FIX ME identifier, constant);
}

vector<Declaration*>* createDeclarationList(Declaration* exp, vector<Declaration*>* list)
{
	if (list == nullptr)
	{
		list = new vector<Declaration*>();
	}
	list->push_back(exp);
	return list;
}
