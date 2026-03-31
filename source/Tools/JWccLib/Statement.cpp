#include "pch.h"
#include "Statement.h"

using namespace WadeSpace;
using namespace std;

Statement::Statement(TokenType op, BaseStatement* statement) : BaseStatement(op, statement)
{
}
