#include "DirectAbstractDeclarator.h"
#include "AbstractDeclarator.h"
#include "ParameterTypeList.h"
#include "ExpressionNode.h"

using namespace WadeSpace;

DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, ParameterTypeList* parameterTypeList, TokenType type) : abstractDeclarator(nullptr), constantExpression(nullptr), type(type), directAbstractDeclarator(directAbstractDeclarator), parameterTypeList(parameterTypeList)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(ParameterTypeList* parameterTypeList, TokenType type) : abstractDeclarator(nullptr), constantExpression(nullptr), type(type), directAbstractDeclarator(nullptr), parameterTypeList(parameterTypeList)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, ExpressionNode* constantExpression, TokenType type) : abstractDeclarator(nullptr), constantExpression(constantExpression), type(type), directAbstractDeclarator(directAbstractDeclarator), parameterTypeList(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, TokenType type) : abstractDeclarator(nullptr), constantExpression(nullptr), type(type), directAbstractDeclarator(directAbstractDeclarator), parameterTypeList(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(TokenType type) : abstractDeclarator(nullptr), constantExpression(nullptr), type(type), directAbstractDeclarator(nullptr), parameterTypeList(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(ExpressionNode* constantExpression) : abstractDeclarator(nullptr), constantExpression(constantExpression), type(NONE), directAbstractDeclarator(nullptr), parameterTypeList(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator) : abstractDeclarator(abstractDeclarator), constantExpression(nullptr), type(NONE), directAbstractDeclarator(nullptr), parameterTypeList(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator() : abstractDeclarator(nullptr), constantExpression(nullptr), type(NONE), directAbstractDeclarator(nullptr), parameterTypeList(nullptr)
{
}

DirectAbstractDeclarator::~DirectAbstractDeclarator()
{
	delete abstractDeclarator;
	delete constantExpression;
	delete directAbstractDeclarator;
	delete parameterTypeList;
}
