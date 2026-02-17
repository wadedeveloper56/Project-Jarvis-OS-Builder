#include "pch.h"
#include "DirectAbstractDeclarator.h"
#include "AbstractDeclarator.h"
#include "ParameterTypeList.h"
#include "Expression.h"

using namespace WadeSpace;


DirectAbstractDeclarator::DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator, vector<DirectAbstractDeclaratorNode*>* list) : abstractDeclarator(abstractDeclarator), list(list)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator() : abstractDeclarator(nullptr), list(nullptr)
{
}

AbstractDeclarator* DirectAbstractDeclarator::getAbstractDeclarator() const
{
	return abstractDeclarator;
}

vector<DirectAbstractDeclaratorNode*>* DirectAbstractDeclarator::getList() const
{
	return list;
}

