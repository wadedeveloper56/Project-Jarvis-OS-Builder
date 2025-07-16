#include "BaseStatement.h"

using namespace WadeSpace;
using namespace std;

BaseStatement::BaseStatement(TokenType op, BaseStatement& es1, BaseStatement& es2, Expression& exp, BaseStatement& statement) :op(op), identifier(""), exp(exp), statement(nullopt), es1(es1), es2(es2) {}
BaseStatement::BaseStatement(TokenType op, BaseStatement& es1, BaseStatement& es2, BaseStatement& statement) :op(NONE), identifier(""), exp(nullopt), statement(nullopt), es1(nullopt), es2(nullopt) {}
BaseStatement::BaseStatement(TokenType op, Expression& exp, BaseStatement& statement) :op(op), identifier(""), exp(exp), statement(statement), es1(nullopt), es2(nullopt) {}
BaseStatement::BaseStatement(TokenType op, Expression& exp) :op(op), identifier(""), exp(exp), statement(nullopt), es1(nullopt), es2(nullopt) {}
BaseStatement::BaseStatement(TokenType op) :op(op), identifier(""), exp(nullopt), statement(nullopt), es1(nullopt), es2(nullopt) {}
BaseStatement::BaseStatement(TokenType op, string identifier) :op(op), identifier(""), exp(nullopt), statement(nullopt), es1(nullopt), es2(nullopt) {}
BaseStatement::BaseStatement() :op(NONE), identifier(""), exp(nullopt), statement(nullopt), es1(nullopt), es2(nullopt) {}
BaseStatement::~BaseStatement() {}
