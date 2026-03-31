#include "pch.h"
#include "DirectDeclarator.h"
#include "ParameterTypeList.h"
#include "Declarator.h"
#include "ExpressionTree.h"

using namespace WadeSpace;
using namespace std;

DirectDeclarator::DirectDeclarator(
	CTokenPtr identifier,
	CTokenPtr token1,
	CTokenPtr token2,
	Declarator* const declarator,
	DirectDeclarator* const directDeclarator,
	ExpressionTree* const constantExpression,
	ParameterTypeList* const parameterTypeList,
	vector<CTokenPtr>* const vectorOfStrings)
	: identifier(identifier),
	  token1(token1),
	  token2(token2),
	  declarator(declarator),
	  directDeclarator(directDeclarator),
	  constantExpression(constantExpression),
	  parameterTypeList(parameterTypeList),
	  vectorOfStrings(vectorOfStrings)
{
}

