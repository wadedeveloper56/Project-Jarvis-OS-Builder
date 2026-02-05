#include "pch.h"
#include "ExpressionStatement.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

ExpressionStatement::ExpressionStatement(Expression* exp) : BaseStatement(NONE, exp)
{
}

ExpressionStatement::ExpressionStatement() : BaseStatement()
{
}

ExpressionStatement::~ExpressionStatement()
{
}
