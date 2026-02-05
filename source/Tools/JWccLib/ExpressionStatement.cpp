#include "pch.h"
#include "ExpressionStatement.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

ExpressionStatement::ExpressionStatement(ExpressionNode* exp) : BaseStatement(NONE, exp)
{
}

ExpressionStatement::ExpressionStatement() : BaseStatement()
{
}

ExpressionStatement::~ExpressionStatement()
{
}
