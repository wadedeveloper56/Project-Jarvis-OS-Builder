#include "JumpStatement.h"
#include "ExpressionNode.h"

using namespace WadeSpace;
using namespace std;

JumpStatement::JumpStatement(TokenType op, ExpressionNode* exp) : BaseStatement(op, exp)
{
}

JumpStatement::JumpStatement(TokenType op) : BaseStatement(op)
{
}

JumpStatement::JumpStatement(TokenType op, string& identifier) : BaseStatement(op, identifier)
{
}

JumpStatement::JumpStatement() : BaseStatement()
{
}

JumpStatement::~JumpStatement()
{
}
