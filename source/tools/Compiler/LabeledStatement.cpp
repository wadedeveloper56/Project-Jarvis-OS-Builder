#include "LabeledStatement.h"

using namespace WadeSpace;
using namespace std;

LabeledStatement::LabeledStatement(string identifier, BaseStatement* statement) : BaseStatement(identifier, statement)
{
}

LabeledStatement::LabeledStatement(TokenType op, ConstantExpression* exp, BaseStatement* statement) : BaseStatement(
	op, exp, statement)
{
}

LabeledStatement::LabeledStatement(TokenType op, BaseStatement* statement) : BaseStatement(op, statement)
{
}

LabeledStatement::LabeledStatement() : BaseStatement()
{
}

LabeledStatement::~LabeledStatement()
{
}
