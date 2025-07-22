#include "ExternalDeclaration.h"

using namespace WadeSpace;
using namespace std;

ExternalDeclaration::ExternalDeclaration(FunctionDefinition* fd) : fd(fd), dec(nullptr)
{
}

ExternalDeclaration::ExternalDeclaration(Declaration* dec) : fd(nullptr), dec(dec)
{
}

ExternalDeclaration::ExternalDeclaration() : fd(nullptr), dec(nullptr)
{
}

ExternalDeclaration::~ExternalDeclaration()
{
}

string ExternalDeclaration::toString()
{
	if (fd != NULL) return "Function";
	else return "Declaration";
}

bool ExternalDeclaration::isFunction() const { return fd != NULL; }
bool ExternalDeclaration::isDeclaration() const { return dec != NULL; }
FunctionDefinition* ExternalDeclaration::getFunction() const { return fd; }
Declaration* ExternalDeclaration::getDeclaration() const { return dec; }
