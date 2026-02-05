#pragma once

#include "Declaration.h"
#include "Constant.h"

using namespace std;
using namespace WadeSpace;

Expression* createPrimaryExpression(string identifier, Constant* constant);
vector<Declaration*>* createDeclarationList(Declaration* exp, vector<Declaration*>* list);

