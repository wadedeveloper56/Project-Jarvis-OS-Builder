#include "BaseStatement.h"

using namespace WadeSpace;
using namespace std;

BaseStatement::BaseStatement(string identifier, BaseStatement* statement) :op(NONE), identifier(identifier), contExp(NULL), exp(NULL), statement(statement), es1(NULL), es2(NULL), statement2(NULL), statementList(NULL), declarationList(NULL) {}
BaseStatement::BaseStatement(TokenType op, ConstantExpression* exp, BaseStatement* statement) :op(op), identifier(""), contExp(exp), exp(NULL), statement(statement), es1(NULL), es2(NULL), statement2(NULL), statementList(NULL), declarationList(NULL) {}
BaseStatement::BaseStatement(TokenType op, BaseStatement* statement) :op(op), identifier(""), contExp(NULL), exp(NULL), statement(statement), es1(NULL), es2(NULL), statement2(NULL), statementList(NULL), declarationList(NULL) {}
BaseStatement::BaseStatement(vector<BaseStatement*>* statementList) : op(NONE), identifier(""), contExp(NULL), exp(NULL), statement(NULL), es1(NULL), es2(NULL), statement2(NULL), statementList(statementList), declarationList(NULL) {}
BaseStatement::BaseStatement(vector<Declaration*>* declarationList) : op(NONE), identifier(""), contExp(NULL), exp(NULL), statement(NULL), es1(NULL), es2(NULL), statement2(NULL), statementList(NULL), declarationList(declarationList) {}
BaseStatement::BaseStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList) : op(NONE), identifier(""), contExp(NULL), exp(NULL), statement(NULL), es1(NULL), es2(NULL), statement2(NULL), statementList(statementList), declarationList(declarationList) {}
BaseStatement::BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, Expression* exp, BaseStatement* statement) :op(op), identifier(""), contExp(NULL), exp(exp), statement(statement), es1(es1), es2(es2), statement2(NULL), statementList(NULL), declarationList(NULL) {}
BaseStatement::BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement) :op(op), identifier(""), contExp(NULL), exp(NULL), statement(statement), es1(NULL), es2(NULL), statement2(NULL), statementList(NULL), declarationList(NULL) {}
BaseStatement::BaseStatement(TokenType op, Expression* exp, BaseStatement* ifStatement, BaseStatement* elseStatement) :op(op), identifier(""), contExp(NULL), exp(exp), statement(ifStatement), es1(NULL), es2(NULL), statement2(elseStatement), statementList(NULL), declarationList(NULL) {}
BaseStatement::BaseStatement(TokenType op, Expression* exp, BaseStatement* statement) :op(op), identifier(""), contExp(NULL), exp(exp), statement(statement), es1(NULL), es2(NULL), statement2(NULL), statementList(NULL), declarationList(NULL) {}
BaseStatement::BaseStatement(TokenType op, Expression* exp) :op(op), identifier(""), contExp(NULL), exp(exp), statement(NULL), es1(NULL), es2(NULL), statement2(NULL), statementList(NULL), declarationList(NULL) {}
BaseStatement::BaseStatement(TokenType op) :op(op), identifier(""), contExp(NULL), exp(NULL), statement(NULL), es1(NULL), es2(NULL), statement2(NULL), statementList(NULL), declarationList(NULL) {}
BaseStatement::BaseStatement(TokenType op, string identifier) :op(op), identifier(""), contExp(NULL), exp(NULL), statement(NULL), es1(NULL), es2(NULL), statement2(NULL), statementList(NULL), declarationList(NULL) {}
BaseStatement::BaseStatement() :op(NONE), identifier(""), contExp(NULL), exp(NULL), statement(NULL), es1(NULL), es2(NULL), statement2(NULL), statementList(NULL), declarationList(NULL) {}
BaseStatement::~BaseStatement() {
	if (exp) delete exp;
	if (contExp) delete contExp;
	if (statement) delete statement;
	if (es1) delete es1;
	if (es2) delete es2;
	if (statement2) delete statement2;
	for (BaseStatement* obj : *statementList) {
		delete obj;
	}
	statementList->clear();
	delete statementList;
	for (Declaration* obj : *declarationList) {
		delete obj;
	}
	declarationList->clear();
	delete declarationList;
}
