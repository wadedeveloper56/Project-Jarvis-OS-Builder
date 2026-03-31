#include "pch.h"
#include "IterationStatement.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

IterationStatement::IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, ExpressionTree* exp, BaseStatement* statement) 
	: BaseStatement(op, es1, es2, exp, statement)
{
}

IterationStatement::IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement) 
	: BaseStatement(op, es1, es2, statement)
{
}

IterationStatement::IterationStatement(TokenType op, ExpressionTree* identifier, BaseStatement* statement)
	: BaseStatement(op, identifier, statement)
{
}
