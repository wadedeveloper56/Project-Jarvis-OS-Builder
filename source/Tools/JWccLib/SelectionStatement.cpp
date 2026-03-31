#include "pch.h"
#include "SelectionStatement.h"

using namespace WadeSpace;
using namespace std;

SelectionStatement::SelectionStatement(TokenType op, ExpressionTree* exp, BaseStatement* ifStatement, BaseStatement* elseStatement) 
	: BaseStatement(op, exp, ifStatement, elseStatement)
{
}

SelectionStatement::SelectionStatement(TokenType op, ExpressionTree* exp, BaseStatement* statement) : BaseStatement(op, exp, statement)
{
}
