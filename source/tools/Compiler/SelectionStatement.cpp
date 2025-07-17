#include "SelectionStatement.h"

using namespace WadeSpace;
using namespace std;

SelectionStatement::SelectionStatement(TokenType op, Expression* exp, BaseStatement* ifStatement, BaseStatement* elseStatement) :BaseStatement(op, exp, ifStatement, elseStatement) {}
SelectionStatement::SelectionStatement(TokenType op, Expression* exp, BaseStatement* statement) :BaseStatement(op, exp, statement) {}
SelectionStatement::SelectionStatement() :BaseStatement() {}
SelectionStatement::~SelectionStatement() {}
