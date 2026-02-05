#include "pch.h"
#include "debug.h"
#include "Expression.h"

using namespace std;
using namespace WadeSpace;

ExpressionNode* createPrimaryExpression(string identifier, Constant* constant)
{
	return new ExpressionNode(identifier, constant);
}

vector<Declaration*>* createDeclarationList(Declaration* exp, vector<Declaration*>* list)
{
	if (list == nullptr)
	{
		list = new vector<Declaration*>();
	}
	list->push_back(exp);
	return list;
}
