#include "ExternalDeclaration.h"

using namespace WadeSpace;
using namespace std;

ExternalDeclaration::ExternalDeclaration(FunctionDefinition* fd) :fd(fd), dec(NULL) {}
ExternalDeclaration::ExternalDeclaration(Declaration* dec) :fd(NULL), dec(dec) {}
ExternalDeclaration::ExternalDeclaration() :fd(NULL), dec(NULL) {}
ExternalDeclaration::~ExternalDeclaration() {}
string ExternalDeclaration::toString() {
	if (fd!=NULL) return "Function"; else return "Declaration";
}
bool ExternalDeclaration::isFunction() const { return fd!=NULL; }
bool ExternalDeclaration::isDeclaration() const { return dec!=NULL; }
FunctionDefinition* ExternalDeclaration::getFunction() const { return fd; }
Declaration* ExternalDeclaration::getDeclaration() const { return dec; }
