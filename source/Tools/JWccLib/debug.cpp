#include "pch.h"
#include "debug.h"
#include "Expression.h"

using namespace std;
using namespace WadeSpace;

Constant* createConstant(const optional<uint64_t>& iConst, const optional<long double>& fConst,const optional<string>& strConst, const optional<TokenType>& type)
{
	return new Constant(iConst,fConst,strConst,type);
}

Declarator* createDeclarator(Pointer* pointer, DirectDeclarator* directDeclarator)
{
	return new Declarator(pointer, directDeclarator);
}

DirectDeclarator* createDirectDeclarator(const optional<string>& identifier,const optional<int>& token1,const optional<int>& token2,Declarator* const declarator,DirectDeclarator* const directDeclarator,Expression* const constantExpression,ParameterTypeList* const parameterTypeList,vector<string>* const vectorOfStrings)
{
	return new DirectDeclarator(identifier,token1,token2,declarator,directDeclarator,constantExpression,parameterTypeList,vectorOfStrings);
}

DeclarationSpecifiers* createDeclarationSpecifiers(StorageClassSpecifier* const storageClassSpecifier,TypeSpecifier* const typeSpecifier,TypeQualifier* const typeQualifier,DeclarationSpecifiers* const declarationSpecifiers)
{
	return new DeclarationSpecifiers(storageClassSpecifier, typeSpecifier, typeQualifier, declarationSpecifiers);
}

StorageClassSpecifier* createStorageClassSpecifier(const TokenPtr token)
{
	return new StorageClassSpecifier(token);
}

Expression* createPrimaryExpression(const optional<string>& identifier, Constant* constant)
{
	return new Expression(identifier, constant);
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
