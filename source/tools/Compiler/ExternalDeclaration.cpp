#include "ExternalDeclaration.h"

using namespace WadeSpace;
using namespace std;

ExternalDeclaration::ExternalDeclaration(FunctionDefinition& fd) :fd(fd), dec(nullopt) {}
ExternalDeclaration::ExternalDeclaration(Declaration& dec) :fd(nullopt), dec(dec) {}
ExternalDeclaration::ExternalDeclaration():fd(nullopt),dec(nullopt) {}
ExternalDeclaration::~ExternalDeclaration() {}