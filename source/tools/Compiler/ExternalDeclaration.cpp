#include "ExternalDeclaration.h"

using namespace WadeSpace;
using namespace std;

ExternalDeclaration::ExternalDeclaration(FunctionDefinition& fd) :fd(fd), dec(nullopt) {}
ExternalDeclaration::ExternalDeclaration(Declaration& dec) :fd(nullopt), dec(dec) {}
ExternalDeclaration::ExternalDeclaration() :fd(nullopt), dec(nullopt) {}
ExternalDeclaration::~ExternalDeclaration() {}
string ExternalDeclaration::toString() {
	if (fd.has_value()) return "Function"; else return "Declaration";
}
bool ExternalDeclaration::isFunction() const { return fd.has_value(); }
bool ExternalDeclaration::isDeclaration() const { return dec.has_value(); }
FunctionDefinition ExternalDeclaration::getFunction() const { return fd.value(); }
Declaration ExternalDeclaration::getDeclaration() const { return dec.value(); }
