#include "pch.h"
#include "Initializer.h"
#include "Expression.h"

using namespace WadeSpace;

Initializer::Initializer(Expression* assignmentExpression) : assignmentExpression(assignmentExpression),
                                                             initializerList(nullptr)
{
}

Initializer::Initializer(vector<Initializer*>* initializerList) : assignmentExpression(nullptr),
                                                                  initializerList(initializerList)
{
}

Initializer::Initializer() : assignmentExpression(nullptr), initializerList(nullptr)
{
}

Initializer::Initializer(const Initializer& other)
	: assignmentExpression(new Expression(*other.assignmentExpression)),
	initializerList(new vector<Initializer*>(*other.initializerList))
{
}

Initializer::Initializer(Initializer&& other) noexcept
	: assignmentExpression(new Expression(*other.assignmentExpression)),
	initializerList(new vector<Initializer*>(*other.initializerList))
{
}

Initializer& Initializer::operator=(const Initializer& other)
{
	if (this == &other)
		return *this;
	assignmentExpression = new Expression(*other.assignmentExpression);
	initializerList = new vector<Initializer*>(*other.initializerList);
	return *this;
}

Initializer& Initializer::operator=(Initializer&& other) noexcept
{
	if (this == &other)
		return *this;
	assignmentExpression = new Expression(*other.assignmentExpression);
	initializerList = new vector<Initializer*>(*other.initializerList);
	return *this;
}

Initializer::~Initializer()
{
	delete assignmentExpression;
	for (Initializer* ptr : *initializerList)
	{
		delete ptr;
	}
	delete initializerList;
}

Expression* Initializer::getAssignmentExpression() const
{
	return assignmentExpression;
}

vector<Initializer*>* Initializer::getInitializerList() const
{
	return initializerList;
}
