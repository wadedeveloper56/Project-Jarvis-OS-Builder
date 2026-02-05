#pragma once

#include "Declaration.h"
#include "Constant.h"

using namespace std;
using namespace WadeSpace;

Expression* createPrimaryExpression(const optional<string>& identifier, Constant* constant);
vector<Declaration*>* createDeclarationList(Declaration* exp, vector<Declaration*>* list);

