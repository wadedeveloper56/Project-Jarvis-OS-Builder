#include "pch.h"
#include "JumpStatement.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

JumpStatement::JumpStatement(TokenType op, ExpressionTree* exp) : BaseStatement(op, exp)
{
}

JumpStatement::JumpStatement(TokenType op) : BaseStatement(op)
{
}

JumpStatement::JumpStatement(TokenType op, CTokenPtr identifier) : BaseStatement(op, identifier)
{
}
