#include "BaseStatement.h"

using namespace WadeSpace;
using namespace std;

BaseStatement::BaseStatement(string identifier, BaseStatement& statement) :op(NONE), identifier(identifier), contExp(nullopt), exp(nullopt), statement(statement), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::BaseStatement(TokenType op, ConstantExpression& exp, BaseStatement& statement) :op(op), identifier(""), contExp(exp), exp(nullopt), statement(statement), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::BaseStatement(TokenType op, BaseStatement& statement) :op(op), identifier(""), contExp(nullopt), exp(nullopt), statement(statement), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::BaseStatement(vector<BaseStatement>& statementList) : op(NONE), identifier(""), contExp(nullopt), exp(nullopt), statement(nullopt), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(statementList), declarationList(nullopt) {}
BaseStatement::BaseStatement(vector<Declaration>& declarationList) : op(NONE), identifier(""), contExp(nullopt), exp(nullopt), statement(nullopt), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(nullopt), declarationList(declarationList) {}
BaseStatement::BaseStatement(vector<BaseStatement>& statementList, vector<Declaration> declarationList) : op(NONE), identifier(""), contExp(nullopt), exp(nullopt), statement(nullopt), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(statementList), declarationList(declarationList) {}
BaseStatement::BaseStatement(TokenType op, BaseStatement& es1, BaseStatement& es2, Expression& exp, BaseStatement& statement) :op(op), identifier(""), contExp(nullopt), exp(exp), statement(statement), es1(es1), es2(es2), statement2(nullopt), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::BaseStatement(TokenType op, BaseStatement& es1, BaseStatement& es2, BaseStatement& statement) :op(op), identifier(""), contExp(nullopt), exp(nullopt), statement(statement), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::BaseStatement(TokenType op, Expression& exp, BaseStatement& ifStatement, BaseStatement& elseStatement) :op(op), identifier(""), contExp(nullopt), exp(exp), statement(ifStatement), es1(nullopt), es2(nullopt), statement2(elseStatement), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::BaseStatement(TokenType op, Expression& exp, BaseStatement& statement) :op(op), identifier(""), contExp(nullopt), exp(exp), statement(statement), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::BaseStatement(TokenType op, Expression& exp) :op(op), identifier(""), contExp(nullopt), exp(exp), statement(nullopt), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::BaseStatement(TokenType op) :op(op), identifier(""), contExp(nullopt), exp(nullopt), statement(nullopt), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::BaseStatement(TokenType op, string identifier) :op(op), identifier(""), contExp(nullopt), exp(nullopt), statement(nullopt), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::BaseStatement() :op(NONE), identifier(""), contExp(nullopt), exp(nullopt), statement(nullopt), es1(nullopt), es2(nullopt), statement2(nullopt), statementList(nullopt), declarationList(nullopt) {}
BaseStatement::~BaseStatement() {}
