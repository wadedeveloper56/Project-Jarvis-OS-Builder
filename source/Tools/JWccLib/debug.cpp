#include "pch.h"
#include "debug.h"
#include "Expression.h"

using namespace std;
using namespace WadeSpace;

vector<BaseStatement*>* createStatementList(BaseStatement* statement, vector<BaseStatement*>* list)
{
	if (list == nullptr)
	{
		list = new vector<BaseStatement*>();
	}
	list->push_back(statement);
	return list;
}

vector<Initializer*>* createInitializerList(Initializer* initializer, vector<Initializer*>* list)
{
	if (list == nullptr)
	{
		list = new vector<Initializer*>();
	}
	list->push_back(initializer);
	return list;
}

DirectAbstractDeclarator* createDirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator, vector<DirectAbstractDeclaratorNode*>* list)
{
	return new DirectAbstractDeclarator(abstractDeclarator, list);
}

DirectAbstractDeclarator* createDirectAbstractDeclarator(DirectAbstractDeclarator* dad, AbstractDeclarator* abstractDeclarator, ParameterTypeList* parameterTypeList, Expression* constantExpression, TokenType type)
{
	if (dad != nullptr)
	{
		vector<DirectAbstractDeclaratorNode*>* list = dad->getList();
		DirectAbstractDeclaratorNode* node = new DirectAbstractDeclaratorNode(parameterTypeList, constantExpression, type);
		list->push_back(node);
		return new DirectAbstractDeclarator(dad->getAbstractDeclarator(), list);
	}
	else
	{
		vector<DirectAbstractDeclaratorNode*>* list = new vector<DirectAbstractDeclaratorNode*>();
		DirectAbstractDeclaratorNode* node = new DirectAbstractDeclaratorNode(parameterTypeList, constantExpression, type);
		list->push_back(node);
		return new DirectAbstractDeclarator(abstractDeclarator, list);
	}
}

vector<TokenPtr>* createIdentifierList(const TokenPtr identifier, vector<TokenPtr>* list)
{
	if (list == nullptr)
	{
		list = new vector<TokenPtr>();
	}
	list->push_back(identifier);
	return list;
}

vector<ParameterDeclaration*>* createParameterList(ParameterDeclaration* value1, vector<ParameterDeclaration*>* list)
{
	if (list == nullptr)
	{
		list = new vector<ParameterDeclaration*>();
	}
	list->push_back(value1);
	return list;
}

vector<TypeQualifier*>* createTypeQualifierList(TypeQualifier* value1, vector<TypeQualifier*>* list)
{
	if (list == nullptr)
	{
		list = new vector<TypeQualifier*>();
	}
	list->push_back(value1);
	return list;
}

vector<Enumerator*>* createEnumeratorList(Enumerator* value1, vector<Enumerator*>* list)
{
	if (list == nullptr)
	{
		list = new vector<Enumerator*>();
	}
	list->push_back(value1);
	return list;
}

vector<StructDeclarator*>* createStructDeclaratorList(StructDeclarator* value1, vector<StructDeclarator*>* list)
{
	if (list == nullptr)
	{
		list = new vector<StructDeclarator*>();
	}
	list->push_back(value1);
	return list;
}

vector<StructDeclaration*>* createStructDeclarationList(StructDeclaration* value1, vector<StructDeclaration*>* list)
{
	if (list == nullptr)
	{
		list = new vector<StructDeclaration*>();
	}
	list->push_back(value1);
	return list;
}

InitDeclarator* createInitDeclarator(Declarator* declarator, Initializer* initializer)
{
	return new InitDeclarator(declarator, initializer);
}

Declaration* createDeclaration(DeclarationSpecifiers* declarationSpecifiers, vector<InitDeclarator*>* vectorInitDeclarator)
{
	return new Declaration(declarationSpecifiers, vectorInitDeclarator);
}

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
	TokenPtr token1,
	TokenPtr token2,
	Expression* lexp,
	Expression* exp1,
	Expression* exp2,
	vector<Expression*>* argumentList,
	TokenPtr identifier,
	vector<Initializer*>* initializerList,
	TypeName* typeName,
	TokenPtr token3,
	Expression* left,
	TokenPtr op,
	Expression* right)
{
	return new Expression(new NodeData(type, token1, token2, lexp, exp1, exp2, argumentList, identifier, initializerList, typeName, token3), left, op, right);
}

Constant* createConstant(const TokenPtr iConst, const TokenPtr fConst, const TokenPtr strConst, const optional<TokenType>& type)
{
	return new Constant(iConst, fConst, strConst, type);
}

Declarator* createDeclarator(Pointer* pointer, DirectDeclarator* directDeclarator)
{
	return new Declarator(pointer, directDeclarator);
}

DirectDeclarator* createDirectDeclarator(TokenPtr identifier, TokenPtr token1, TokenPtr token2, Declarator* const declarator, DirectDeclarator* const directDeclarator, Expression* const constantExpression, ParameterTypeList* const parameterTypeList, vector<TokenPtr>* const vectorOfStrings)
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

Expression* createPrimaryExpression(const TokenPtr identifier, Constant* constant)
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
