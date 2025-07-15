#include "BaseStatement.h"

using namespace WadeSpace;
using namespace std;

BaseStatement::BaseStatement(TokenType op, Expression& exp) :op(op), identifier(""), exp(exp) {}
BaseStatement::BaseStatement(TokenType op) :op(op), identifier(""), exp(nullopt) {}
BaseStatement::BaseStatement(TokenType op, string identifier) :op(op), identifier(""), exp(nullopt) {}
BaseStatement::BaseStatement() :op(NONE), identifier(""), exp(nullopt) {}
BaseStatement::~BaseStatement() {}
