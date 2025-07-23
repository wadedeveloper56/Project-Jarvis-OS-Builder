#include "JumpStatement.h"

using namespace WadeSpace;
using namespace std;

JumpStatement::JumpStatement(TokenType op, Expression* exp) : BaseStatement(op, exp)
{
}

JumpStatement::JumpStatement(TokenType op) : BaseStatement(op)
{
}

JumpStatement::JumpStatement(TokenType op, const string& identifier) : BaseStatement(op, identifier)
{
}

JumpStatement::JumpStatement() : BaseStatement()
{
}

JumpStatement::~JumpStatement()
{
}
