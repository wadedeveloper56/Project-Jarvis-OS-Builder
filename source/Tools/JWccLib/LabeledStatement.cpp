#include "pch.h"
#include "LabeledStatement.h"

using namespace WadeSpace;
using namespace std;

LabeledStatement::LabeledStatement(CTokenPtr identifier, BaseStatement* statement) : BaseStatement(identifier, statement)
{
}

LabeledStatement::LabeledStatement(TokenType op, ExpressionTree* exp, BaseStatement* statement) : BaseStatement(op, exp, statement)
{
}

LabeledStatement::LabeledStatement(TokenType op, BaseStatement* statement) : BaseStatement(op, statement)
{
}
