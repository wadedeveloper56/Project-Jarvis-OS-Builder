#include "pch.h"
#include "DirectAbstractDeclarator.h"
#include "AbstractDeclarator.h"
#include "ParameterTypeList.h"
#include "ExpressionTree.h"

using namespace WadeSpace;

DirectAbstractDeclaratorNode::DirectAbstractDeclaratorNode(ParameterTypeList* const parameterTypeList,
                                                           ExpressionTree* const constantExpression,
                                                           optional<TokenType> type)
	: parameterTypeList(parameterTypeList),
	  constantExpression(constantExpression),
	  type(type)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator, vector<DirectAbstractDeclaratorNode*>* list) :
	abstractDeclarator(abstractDeclarator), list(list)
{
}

