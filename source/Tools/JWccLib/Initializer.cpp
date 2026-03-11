#include "pch.h"
#include "Initializer.h"
#include "ExpressionTree.h"

using namespace WadeSpace;

Initializer::Initializer(ExpressionTree* assignmentExpression) : assignmentExpression(assignmentExpression), initializerList(nullptr)
{
}

Initializer::Initializer(vector<Initializer*>* initializerList) : assignmentExpression(nullptr), initializerList(initializerList)
{
}

Initializer::Initializer() : assignmentExpression(nullptr), initializerList(nullptr)
{
}

Initializer::Initializer(const Initializer& other)
{
	delete assignmentExpression;
	if (initializerList != nullptr)
	{
		for (Initializer* ptr : *initializerList)
		{
			delete ptr;
		}
		delete initializerList;
	}
	assignmentExpression = other.assignmentExpression ? new ExpressionTree(*other.assignmentExpression) : nullptr;
	initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
}

Initializer::Initializer(Initializer&& other) noexcept
{
	assignmentExpression = other.assignmentExpression ? new ExpressionTree(*other.assignmentExpression) : nullptr;
	initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
}

Initializer& Initializer::operator=(const Initializer& other)
{
	if (this == &other)
		return *this;
	assignmentExpression = other.assignmentExpression ? new ExpressionTree(*other.assignmentExpression) : nullptr;
	initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
	return *this;
}

Initializer& Initializer::operator=(Initializer&& other) noexcept
{
	if (this == &other)
		return *this;
	assignmentExpression = other.assignmentExpression ? new ExpressionTree(*other.assignmentExpression) : nullptr;
	initializerList = other.initializerList ? new vector<Initializer*>(*other.initializerList) : nullptr;
	return *this;
}

Initializer::~Initializer()
{
	delete assignmentExpression;
	if (initializerList != nullptr)
	{
		for (auto ptr : *initializerList)
		{
			delete ptr;
		}
		delete initializerList;
	}
}

ExpressionTree* Initializer::getAssignmentExpression() const
{
	return assignmentExpression;
}

vector<Initializer*>* Initializer::getInitializerList() const
{
	return initializerList;
}

bool Initializer::hasAssignmentExpression() const
{
	return assignmentExpression != nullptr;
}

bool Initializer::hasInitializerList() const
{
	return initializerList != nullptr;
}