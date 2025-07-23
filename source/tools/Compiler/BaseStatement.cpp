#include "BaseStatement.h"

using namespace WadeSpace;
using namespace std;

BaseStatement::BaseStatement(string identifier, BaseStatement* statement) : op(NONE), identifier(identifier),
                                                                            contExp(nullptr), exp(nullptr),
                                                                            statement(statement), es1(nullptr),
                                                                            es2(nullptr), statement2(nullptr),
                                                                            statementList(nullptr),
                                                                            declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, ConstantExpression* exp, BaseStatement* statement) : op(op), identifier(""),
	contExp(exp), exp(nullptr), statement(statement), es1(nullptr), es2(nullptr), statement2(nullptr),
	statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, BaseStatement* statement) : op(op), identifier(""), contExp(nullptr),
                                                                       exp(nullptr), statement(statement), es1(nullptr),
                                                                       es2(nullptr), statement2(nullptr),
                                                                       statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(vector<BaseStatement*>* statementList) : op(NONE), identifier(""), contExp(nullptr),
                                                                      exp(nullptr), statement(nullptr), es1(nullptr),
                                                                      es2(nullptr), statement2(nullptr),
                                                                      statementList(statementList),
                                                                      declarationList(nullptr)
{
}

BaseStatement::BaseStatement(vector<Declaration*>* declarationList) : op(NONE), identifier(""), contExp(nullptr),
                                                                      exp(nullptr), statement(nullptr), es1(nullptr),
                                                                      es2(nullptr), statement2(nullptr),
                                                                      statementList(nullptr),
                                                                      declarationList(declarationList)
{
}

BaseStatement::BaseStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList) :
	op(NONE), identifier(""), contExp(nullptr), exp(nullptr), statement(nullptr), es1(nullptr), es2(nullptr),
	statement2(nullptr), statementList(statementList), declarationList(declarationList)
{
}

BaseStatement::BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, Expression* exp,
                             BaseStatement* statement) : op(op), identifier(""), contExp(nullptr), exp(exp),
                                                         statement(statement), es1(es1), es2(es2), statement2(nullptr),
                                                         statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement) :
	op(op), identifier(""), contExp(nullptr), exp(nullptr), statement(statement), es1(nullptr), es2(nullptr),
	statement2(nullptr), statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, Expression* exp, BaseStatement* ifStatement, BaseStatement* elseStatement) :
	op(op), identifier(""), contExp(nullptr), exp(exp), statement(ifStatement), es1(nullptr), es2(nullptr),
	statement2(elseStatement), statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, Expression* exp, BaseStatement* statement) : op(op), identifier(""),
	contExp(nullptr), exp(exp), statement(statement), es1(nullptr), es2(nullptr), statement2(nullptr),
	statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, Expression* exp) : op(op), identifier(""), contExp(nullptr), exp(exp),
                                                              statement(nullptr), es1(nullptr), es2(nullptr),
                                                              statement2(nullptr), statementList(nullptr),
                                                              declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op) : op(op), identifier(""), contExp(nullptr), exp(nullptr), statement(nullptr),
                                             es1(nullptr), es2(nullptr), statement2(nullptr), statementList(nullptr),
                                             declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, string identifier) : op(op), identifier(""), contExp(nullptr), exp(nullptr),
                                                                statement(nullptr), es1(nullptr), es2(nullptr),
                                                                statement2(nullptr), statementList(nullptr),
                                                                declarationList(nullptr)
{
}

BaseStatement::BaseStatement() : op(NONE), identifier(""), contExp(nullptr), exp(nullptr), statement(nullptr),
                                 es1(nullptr), es2(nullptr), statement2(nullptr), statementList(nullptr),
                                 declarationList(nullptr)
{
}

BaseStatement::~BaseStatement()
{
	delete exp;
	delete contExp;
	delete statement;
	delete es1;
	delete es2;
	delete statement2;
	for (BaseStatement* obj : *statementList)
	{
		delete obj;
	}
	delete statementList;
	for (Declaration* obj : *declarationList)
	{
		delete obj;
	}
	delete declarationList;
}

string BaseStatement::get_identifier() const
{
	return identifier;
}

Expression* BaseStatement::get_exp() const
{
	return exp;
}

ConstantExpression* BaseStatement::get_cont_exp() const
{
	return contExp;
}

BaseStatement* BaseStatement::get_statement() const
{
	return statement;
}

BaseStatement* BaseStatement::get_es1() const
{
	return es1;
}

BaseStatement* BaseStatement::get_es2() const
{
	return es2;
}

BaseStatement* BaseStatement::get_statement2() const
{
	return statement2;
}

vector<BaseStatement*>* BaseStatement::get_statement_list() const
{
	return statementList;
}

vector<Declaration*>* BaseStatement::get_declaration_list() const
{
	return declarationList;
}
