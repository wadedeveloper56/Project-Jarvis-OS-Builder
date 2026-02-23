#include "pch.h"
#include "InitDeclarator.h"

using namespace WadeSpace;

InitDeclarator::InitDeclarator(Declarator* declarator) : declarator(declarator), initializer(nullptr)
{
}

InitDeclarator::InitDeclarator(Declarator* declarator, Initializer* initializer) : declarator(declarator),
	initializer(initializer)
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
	: declarator(new Declarator(*other.declarator)),
	  initializer(new Initializer(*other.initializer))
{
}

InitDeclarator::InitDeclarator(InitDeclarator&& other) noexcept
	: declarator(new Declarator(*other.declarator)),
	  initializer(new Initializer(*other.initializer))
{
}

InitDeclarator& InitDeclarator::operator=(const InitDeclarator& other)
{
	if (this == &other)
		return *this;
	delete declarator;
	delete initializer;
	declarator = new Declarator(*other.declarator);
	initializer = new Initializer(*other.initializer);
	return *this;
}

InitDeclarator& InitDeclarator::operator=(InitDeclarator&& other) noexcept
{
	if (this == &other)
		return *this;
	delete declarator;
	delete initializer;
	declarator = new Declarator(*other.declarator);
	initializer = new Initializer(*other.initializer);
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

string InitDeclarator::getVariableName() const
{
	TokenPtr identifier = getDeclarator()->getDirectDeclarator()->getIdentifier();
	if (!identifier) identifier = getDeclarator()->getDirectDeclarator()->getDirectDeclarator()->getIdentifier();
	return (identifier) ? identifier->data->repr.symbol.string : "";
}
