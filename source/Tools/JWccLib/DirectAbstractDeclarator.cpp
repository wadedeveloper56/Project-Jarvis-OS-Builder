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
{
	delete abstractDeclarator;
	delete list;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
	list = other.list ? new vector<DirectAbstractDeclaratorNode*>(*other.list) : nullptr;
}

DirectAbstractDeclarator::DirectAbstractDeclarator(DirectAbstractDeclarator&& other) noexcept
{
	delete abstractDeclarator;
	delete list;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
	list = other.list ? new vector<DirectAbstractDeclaratorNode*>(*other.list) : nullptr;
}

DirectAbstractDeclarator& DirectAbstractDeclarator::operator=(const DirectAbstractDeclarator& other)
{
	if (this == &other)
		return *this;
	delete abstractDeclarator;
	delete list;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
	list = other.list ? new vector<DirectAbstractDeclaratorNode*>(*other.list) : nullptr;
	return *this;
}

DirectAbstractDeclarator& DirectAbstractDeclarator::operator=(DirectAbstractDeclarator&& other) noexcept
{
	if (this == &other)
		return *this;
	delete abstractDeclarator;
	delete list;
	abstractDeclarator = other.abstractDeclarator ? new AbstractDeclarator(*other.abstractDeclarator) : nullptr;
	list = other.list ? new vector<DirectAbstractDeclaratorNode*>(*other.list) : nullptr;
	return *this;
}

