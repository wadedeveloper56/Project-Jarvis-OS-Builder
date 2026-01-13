#include "IterationStatement.h"
#include "ExpressionNode.h"

using namespace WadeSpace;
using namespace std;

IterationStatement::IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, ExpressionNode* exp,
                                       BaseStatement* statement) : BaseStatement(op, es1, es2, exp, statement)
{
}

IterationStatement::IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2,
                                       BaseStatement* statement) : BaseStatement(op, es1, es2, statement)
{
}

IterationStatement::IterationStatement(TokenType op, ExpressionNode* identifier, BaseStatement* statement): BaseStatement(
	op, identifier, statement)
{
}

IterationStatement::IterationStatement() : BaseStatement()
{
}

IterationStatement::~IterationStatement()
{
}
