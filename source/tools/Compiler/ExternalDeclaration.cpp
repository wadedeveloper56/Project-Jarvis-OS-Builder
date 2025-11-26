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

bool ExternalDeclaration::isFunction() const { return functionDefinition != nullptr; }
bool ExternalDeclaration::isDeclaration() const { return declaration != nullptr; }
FunctionDefinition* ExternalDeclaration::getFunction() const { return functionDefinition; }
Declaration* ExternalDeclaration::getDeclaration() const { return declaration; }
