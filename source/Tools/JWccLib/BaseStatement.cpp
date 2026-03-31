#include "pch.h"
#include "BaseStatement.h"
#include "ExpressionTree.h"

using namespace WadeSpace;
using namespace std;

BaseStatement::BaseStatement(TokenType op, CTokenPtr identifier, ExpressionTree* const exp, ExpressionTree* const contExp,
                             BaseStatement* const statement, BaseStatement* const es1, BaseStatement* const es2,
                             BaseStatement* const statement2, vector<BaseStatement*>* const statementList,
                             vector<Declaration*>* const declarationList)
	: op(op),
	  identifier(identifier),
	  exp(exp),
	  contExp(contExp),
	  statement(statement),
	  es1(es1),
	  es2(es2),
	  statement2(statement2),
	  statementList(statementList),
	  declarationList(declarationList)
{
}

BaseStatement::BaseStatement(CTokenPtr identifier, BaseStatement* statement) : op(NONE), identifier(identifier),
                                                                              contExp(nullptr), exp(nullptr),
                                                                              statement(statement), es1(nullptr),
                                                                              es2(nullptr), statement2(nullptr),
                                                                              statementList(nullptr),
                                                                              declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, ExpressionTree* exp, BaseStatement* statement) : op(op), identifier(nullptr),
	contExp(exp), exp(nullptr), statement(statement), es1(nullptr), es2(nullptr), statement2(nullptr),
	statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, BaseStatement* statement) : op(op), identifier(nullptr), contExp(nullptr),
                                                                       exp(nullptr), statement(statement), es1(nullptr),
                                                                       es2(nullptr), statement2(nullptr),
                                                                       statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(vector<BaseStatement*>* statementList) : op(NONE), identifier(nullptr), contExp(nullptr),
                                                                      exp(nullptr), statement(nullptr), es1(nullptr),
                                                                      es2(nullptr), statement2(nullptr),
                                                                      statementList(statementList),
                                                                      declarationList(nullptr)
{
}

BaseStatement::BaseStatement(vector<Declaration*>* declarationList) : op(NONE), identifier(nullptr), contExp(nullptr),
                                                                      exp(nullptr), statement(nullptr), es1(nullptr),
                                                                      es2(nullptr), statement2(nullptr),
                                                                      statementList(nullptr),
                                                                      declarationList(declarationList)
{
}

BaseStatement::BaseStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList) :
	op(NONE), identifier(nullptr), contExp(nullptr), exp(nullptr), statement(nullptr), es1(nullptr), es2(nullptr),
	statement2(nullptr), statementList(statementList), declarationList(declarationList)
{
}

BaseStatement::BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, ExpressionTree* exp,
                             BaseStatement* statement) : op(op), identifier(nullptr), contExp(nullptr), exp(exp),
                                                         statement(statement), es1(es1), es2(es2), statement2(nullptr),
                                                         statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement) :
	op(op), identifier(nullptr), contExp(nullptr), exp(nullptr), statement(statement), es1(nullptr), es2(nullptr),
	statement2(nullptr), statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, ExpressionTree* exp, BaseStatement* ifStatement, BaseStatement* elseStatement) :
	op(op), identifier(nullptr), contExp(nullptr), exp(exp), statement(ifStatement), es1(nullptr), es2(nullptr),
	statement2(elseStatement), statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, ExpressionTree* exp) : op(op), identifier(nullptr), contExp(nullptr), exp(exp),
                                                              statement(nullptr), es1(nullptr), es2(nullptr),
                                                              statement2(nullptr), statementList(nullptr),
                                                              declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op) : op(op), identifier(nullptr), contExp(nullptr), exp(nullptr),
                                             statement(nullptr),
                                             es1(nullptr), es2(nullptr), statement2(nullptr), statementList(nullptr),
                                             declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, CTokenPtr identifier) : op(op), identifier(identifier), contExp(nullptr),
                                                                  exp(nullptr),
                                                                  statement(nullptr), es1(nullptr), es2(nullptr),
                                                                  statement2(nullptr), statementList(nullptr),
                                                                  declarationList(nullptr)
{
}

