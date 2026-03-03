#include "pch.h"
#include "ExternalDeclaration.h"
#include <iostream>

using namespace WadeSpace;
using namespace std;
 
ExternalDeclaration::ExternalDeclaration(FunctionDefinition* functionDefinition) : functionDefinition(functionDefinition), declaration(nullptr)
{
}

ExternalDeclaration::ExternalDeclaration(Declaration* declaration) : functionDefinition(nullptr), declaration(declaration)
{
}

ExternalDeclaration::ExternalDeclaration() : functionDefinition(nullptr), declaration(nullptr)
{
}

ExternalDeclaration::~ExternalDeclaration()
{
	delete functionDefinition;
	delete declaration;
}

string ExternalDeclaration::toString()
{
	if (functionDefinition != nullptr) return "Function";
	else return "Declaration";
}

ExternalDeclaration::ExternalDeclaration(const ExternalDeclaration& other)
{
	functionDefinition = other.functionDefinition ? new FunctionDefinition(*other.functionDefinition) : nullptr;
	declaration = other.declaration ? new Declaration(*other.declaration) : nullptr;
}

ExternalDeclaration::ExternalDeclaration(ExternalDeclaration&& other) noexcept
{
	functionDefinition = other.functionDefinition ? new FunctionDefinition(*other.functionDefinition) : nullptr;
	declaration = other.declaration ? new Declaration(*other.declaration) : nullptr;
}

ExternalDeclaration& ExternalDeclaration::operator=(const ExternalDeclaration& other)
{
	if (this == &other)
		return *this;
	functionDefinition = other.functionDefinition ? new FunctionDefinition(*other.functionDefinition) : nullptr;
	declaration = other.declaration ? new Declaration(*other.declaration) : nullptr;
	return *this;
}

ExternalDeclaration& ExternalDeclaration::operator=(ExternalDeclaration&& other) noexcept
{
	if (this == &other)
		return *this;
	functionDefinition = other.functionDefinition ? new FunctionDefinition(*other.functionDefinition) : nullptr;
	declaration = other.declaration ? new Declaration(*other.declaration) : nullptr;
	return *this;
}

bool ExternalDeclaration::isFunction() const
{
	return functionDefinition != nullptr;
}

bool ExternalDeclaration::isDeclaration() const
{
	return declaration != nullptr;
}

FunctionDefinition* ExternalDeclaration::getFunction() const
{
	return functionDefinition;
}

Declaration* ExternalDeclaration::getDeclaration() const
{
	return declaration;
}

