#include "BaseStatement.h"
#include "ExpressionNode.h"

using namespace WadeSpace;
using namespace std;

BaseStatement::BaseStatement(string& identifier, BaseStatement* statement) : op(NONE), identifier(identifier),
contExp(nullptr), exp(nullptr),
statement(statement), es1(nullptr),
es2(nullptr), statement2(nullptr),
statementList(nullptr),
declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, ExpressionNode* exp, BaseStatement* statement) : op(op), identifier(nullopt),
contExp(exp), exp(nullptr), statement(statement), es1(nullptr), es2(nullptr), statement2(nullptr),
statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, BaseStatement* statement) : op(op), identifier(nullopt), contExp(nullptr),
exp(nullptr), statement(statement), es1(nullptr),
es2(nullptr), statement2(nullptr),
statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(vector<BaseStatement*>* statementList) : op(NONE), identifier(nullopt), contExp(nullptr),
exp(nullptr), statement(nullptr), es1(nullptr),
es2(nullptr), statement2(nullptr),
statementList(statementList),
declarationList(nullptr)
{
}

BaseStatement::BaseStatement(vector<Declaration*>* declarationList) : op(NONE), identifier(nullopt), contExp(nullptr),
exp(nullptr), statement(nullptr), es1(nullptr),
es2(nullptr), statement2(nullptr),
statementList(nullptr),
declarationList(declarationList)
{
}

BaseStatement::BaseStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList) :
	op(NONE), identifier(nullopt), contExp(nullptr), exp(nullptr), statement(nullptr), es1(nullptr), es2(nullptr),
	statement2(nullptr), statementList(statementList), declarationList(declarationList)
{
}

BaseStatement::BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, ExpressionNode* exp,
	BaseStatement* statement) : op(op), identifier(nullopt), contExp(nullptr), exp(exp),
	statement(statement), es1(es1), es2(es2), statement2(nullptr),
	statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement) :
	op(op), identifier(nullopt), contExp(nullptr), exp(nullptr), statement(statement), es1(nullptr), es2(nullptr),
	statement2(nullptr), statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, ExpressionNode* exp, BaseStatement* ifStatement, BaseStatement* elseStatement) :
	op(op), identifier(nullopt), contExp(nullptr), exp(exp), statement(ifStatement), es1(nullptr), es2(nullptr),
	statement2(elseStatement), statementList(nullptr), declarationList(nullptr)
{
}
/*
BaseStatement::BaseStatement(TokenType op, ExpressionNode* exp, BaseStatement* statement) : op(op), identifier(nullopt),
contExp(nullptr), exp(exp), statement(statement), es1(nullptr), es2(nullptr), statement2(nullptr),
statementList(nullptr), declarationList(nullptr)
{
}
*/
BaseStatement::BaseStatement(TokenType op, ExpressionNode* exp) : op(op), identifier(nullopt), contExp(nullptr), exp(exp),
statement(nullptr), es1(nullptr), es2(nullptr),
statement2(nullptr), statementList(nullptr),
declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op) : op(op), identifier(nullopt), contExp(nullptr), exp(nullptr), statement(nullptr),
es1(nullptr), es2(nullptr), statement2(nullptr), statementList(nullptr),
declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, string& identifier) : op(op), identifier(identifier), contExp(nullptr), exp(nullptr),
statement(nullptr), es1(nullptr), es2(nullptr),
statement2(nullptr), statementList(nullptr),
declarationList(nullptr)
{
}

BaseStatement::BaseStatement() : op(NONE), identifier(nullopt), contExp(nullptr), exp(nullptr), statement(nullptr),
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

optional<string> BaseStatement::getIdentifier() const
{
	return identifier;
}

ExpressionNode* BaseStatement::getExp() const
{
	return exp;
}

ExpressionNode* BaseStatement::getContExp() const
{
	return contExp;
}

BaseStatement* BaseStatement::getStatement() const
{
	return statement;
}

BaseStatement* BaseStatement::getEs1() const
{
	return es1;
}

BaseStatement* BaseStatement::getEs2() const
{
	return es2;
}

BaseStatement* BaseStatement::getStatement2() const
{
	return statement2;
}

vector<BaseStatement*>* BaseStatement::getStatementList() const
{
	return statementList;
}

vector<Declaration*>* BaseStatement::getDeclarationList() const
{
	return declarationList;
}

