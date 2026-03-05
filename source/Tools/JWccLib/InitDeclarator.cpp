#include "pch.h"
#include "InitDeclarator.h"

using namespace WadeSpace;

InitDeclarator::InitDeclarator(Declarator* declarator) : declarator(declarator), initializer(nullptr)
{
}

InitDeclarator::InitDeclarator(Declarator* declarator, Initializer* initializer) : declarator(declarator), initializer(initializer)
{
}

InitDeclarator::InitDeclarator() : declarator(nullptr), initializer(nullptr)
{
}

InitDeclarator::~InitDeclarator()
{
	delete declarator;
	delete initializer;
}

InitDeclarator::InitDeclarator(const InitDeclarator& other)
{
	delete declarator;
	delete initializer;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
}

InitDeclarator::InitDeclarator(InitDeclarator&& other) noexcept
{
	delete declarator;
	delete initializer;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
}

InitDeclarator& InitDeclarator::operator=(const InitDeclarator& other)
{
	if (this == &other)
		return *this;
	delete declarator;
	delete initializer;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
	return *this;
}

InitDeclarator& InitDeclarator::operator=(InitDeclarator&& other) noexcept
{
	if (this == &other)
		return *this;
	delete declarator;
	delete initializer;
	declarator = other.declarator ? new Declarator(*other.declarator) : nullptr;
	initializer = other.initializer ? new Initializer(*other.initializer) : nullptr;
	return *this;
}

Declarator* InitDeclarator::getDeclarator() const
{
	return declarator;
}

Initializer* InitDeclarator::getInitializer() const
{
	return initializer;
}

bool InitDeclarator::hasDeclarator() const
{
	return declarator != nullptr;
}

bool InitDeclarator::hasInitializer() const
{
	return initializer != nullptr;
}

string InitDeclarator::getVariableName() const
{
	TokenPtr identifier = getDeclarator()->getDirectDeclarator()->getIdentifier();
	if (!identifier) identifier = getDeclarator()->getDirectDeclarator()->getDirectDeclarator()->getIdentifier();
	return (identifier) ? identifier->getSymbolName() : "";
}
