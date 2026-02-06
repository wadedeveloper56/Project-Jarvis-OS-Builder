#pragma once

#include "Declaration.h"
#include "Constant.h"

using namespace std;
using namespace WadeSpace;

StorageClassSpecifier* createStorageClassSpecifier(const int& value, TokenType type);
Expression* createPrimaryExpression(const optional<string>& identifier, Constant* constant);
vector<Declaration*>* createDeclarationList(Declaration* exp, vector<Declaration*>* list);

