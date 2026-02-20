#include "pch.h"
#include "DirectAbstractDeclarator.h"
#include "AbstractDeclarator.h"
#include "ParameterTypeList.h"
#include "Expression.h"

using namespace WadeSpace;

DirectAbstractDeclaratorNode::DirectAbstractDeclaratorNode()
	: parameterTypeList(nullptr),
	  constantExpression(nullptr),
	  type(nullopt)
{
}

DirectAbstractDeclaratorNode::DirectAbstractDeclaratorNode(ParameterTypeList* const parameterTypeList,
                                                           Expression* const constantExpression,
                                                           optional<TokenType> type)
	: parameterTypeList(parameterTypeList),
	  constantExpression(constantExpression),
	  type(type)
{
}

DirectAbstractDeclaratorNode::~DirectAbstractDeclaratorNode()
{
	delete parameterTypeList;
	delete constantExpression;
}

DirectAbstractDeclarator::DirectAbstractDeclarator() : abstractDeclarator(nullptr), list(nullptr)
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator,
                                                   vector<DirectAbstractDeclaratorNode*>* list) :
	abstractDeclarator(abstractDeclarator), list(list)
{
}

DirectAbstractDeclarator::~DirectAbstractDeclarator()
{
	delete abstractDeclarator;
	if (list != nullptr)
	{
		for (auto node : *list)
		{
			delete node;
		}
		delete list;
	}
}

AbstractDeclarator* DirectAbstractDeclarator::getAbstractDeclarator() const
{
	return abstractDeclarator;
}

vector<DirectAbstractDeclaratorNode*>* DirectAbstractDeclarator::getList() const
{
	return list;
}

DirectAbstractDeclarator::DirectAbstractDeclarator(const DirectAbstractDeclarator& other)
	: abstractDeclarator(new AbstractDeclarator(*other.abstractDeclarator)),
	list(new vector<DirectAbstractDeclaratorNode*>(*other.list))
{
}

DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator&& other) noexcept
	: abstractDeclarator(new AbstractDeclarator(*other.abstractDeclarator)),
	list(new vector<DirectAbstractDeclaratorNode*>(*other.list))
{
}

DirectAbstractDeclarator& DirectAbstractDeclarator::operator=(const DirectAbstractDeclarator& other)
{
	if (this == &other)
		return *this;
	abstractDeclarator = new AbstractDeclarator(*other.abstractDeclarator);
	list = new vector<DirectAbstractDeclaratorNode*>(*other.list);
	return *this;
}

DirectAbstractDeclarator& DirectAbstractDeclarator::operator=(DirectAbstractDeclarator&& other) noexcept
{
	if (this == &other)
		return *this;
	abstractDeclarator = new AbstractDeclarator(*other.abstractDeclarator);
	list = new vector<DirectAbstractDeclaratorNode*>(*other.list);
	return *this;
}

