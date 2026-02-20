#include "pch.h"
#include "BaseStatement.h"
#include "Expression.h"

using namespace WadeSpace;
using namespace std;

BaseStatement::BaseStatement(TokenType op, TokenPtr identifier, Expression* const exp, Expression* const contExp,
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

BaseStatement::BaseStatement(TokenPtr identifier, BaseStatement* statement) : op(NONE), identifier(identifier),
                                                                             contExp(nullptr), exp(nullptr),
                                                                             statement(statement), es1(nullptr),
                                                                             es2(nullptr), statement2(nullptr),
                                                                             statementList(nullptr),
                                                                             declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, Expression* exp, BaseStatement* statement) : op(op), identifier(nullptr),
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

BaseStatement::BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, Expression* exp,
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

BaseStatement::BaseStatement(TokenType op, Expression* exp, BaseStatement* ifStatement, BaseStatement* elseStatement) :
	op(op), identifier(nullptr), contExp(nullptr), exp(exp), statement(ifStatement), es1(nullptr), es2(nullptr),
	statement2(elseStatement), statementList(nullptr), declarationList(nullptr)
{
}

BaseStatement::BaseStatement(TokenType op, Expression* exp) : op(op), identifier(nullptr), contExp(nullptr), exp(exp),
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

BaseStatement::BaseStatement(TokenType op, TokenPtr identifier) : op(op), identifier(identifier), contExp(nullptr),
                                                                 exp(nullptr),
                                                                 statement(nullptr), es1(nullptr), es2(nullptr),
                                                                 statement2(nullptr), statementList(nullptr),
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
	delete identifier;
	if (statementList != nullptr)
	{
		for (auto obj : *statementList)
		{
			delete obj;
		}
	}
	delete statementList;
	if (declarationList != nullptr)
	{
		for (auto obj : *declarationList)
		{
			delete obj;
		}
	}
	delete declarationList;
}

TokenPtr BaseStatement::getIdentifier() const
{
	return identifier;
}

Expression* BaseStatement::getExp() const
{
	return exp;
}

Expression* BaseStatement::getContExp() const
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

BaseStatement::BaseStatement(const BaseStatement& other)
	: identifier(other.identifier ? new Token(*other.identifier) : nullptr),
	exp(other.exp ? new Expression(*other.exp) : nullptr),
	contExp(other.contExp ? new Expression(*other.contExp) : nullptr),
	statement(other.statement ? new BaseStatement(*other.statement) : nullptr),
	es1(other.es1 ? new BaseStatement(*other.es1) : nullptr),
	es2(other.es2 ? new BaseStatement(*other.es2) : nullptr),
	statement2(other.statement2 ? new BaseStatement(*other.statement2) : nullptr),
	statementList(other.statementList ? new vector<BaseStatement*>(*other.statementList) : nullptr),
	declarationList(other.declarationList ? new vector<Declaration*>(*other.declarationList) : nullptr)
{
}

BaseStatement::BaseStatement(BaseStatement&& other) noexcept
	: identifier(other.identifier ? new Token(*other.identifier) : nullptr),
	exp(other.exp ? new Expression(*other.exp) : nullptr),
	contExp(other.contExp ? new Expression(*other.contExp) : nullptr),
	statement(other.statement ? new BaseStatement(*other.statement) : nullptr),
	es1(other.es1 ? new BaseStatement(*other.es1) : nullptr),
	es2(other.es2 ? new BaseStatement(*other.es2) : nullptr),
	statement2(other.statement2 ? new BaseStatement(*other.statement2) : nullptr),
	statementList(other.statementList ? new vector<BaseStatement*>(*other.statementList) : nullptr),
	declarationList(other.declarationList ? new vector<Declaration*>(*other.declarationList) : nullptr)
{
}

BaseStatement& BaseStatement::operator=(const BaseStatement& other)
{
	if (this == &other)
		return *this;
	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
	exp = other.exp ? new Expression(*other.exp) : nullptr;
	contExp = other.contExp ? new Expression(*other.contExp) : nullptr;
	statement = other.statement ? new BaseStatement(*other.statement) : nullptr;
	es1 = other.es1 ? new BaseStatement(*other.es1) : nullptr;
	es2 = other.es2 ? new BaseStatement(*other.es2) : nullptr;
	statement2 = other.statement2 ? new BaseStatement(*other.statement2) : nullptr;
	statementList = other.statementList ? new vector<BaseStatement*>(*other.statementList) : nullptr;
	declarationList = other.declarationList ? new vector<Declaration*>(*other.declarationList) : nullptr;
	return *this;
}

BaseStatement& BaseStatement::operator=(BaseStatement&& other) noexcept
{
	if (this == &other)
		return *this;
	identifier = other.identifier ? new Token(*other.identifier) : nullptr;
	exp = other.exp ? new Expression(*other.exp) : nullptr;
	contExp = other.contExp ? new Expression(*other.contExp) : nullptr;
	statement = other.statement ? new BaseStatement(*other.statement) : nullptr;
	es1 = other.es1 ? new BaseStatement(*other.es1) : nullptr;
	es2 = other.es2 ? new BaseStatement(*other.es2) : nullptr;
	statement2 = other.statement2 ? new BaseStatement(*other.statement2) : nullptr;
	statementList = other.statementList ? new vector<BaseStatement*>(*other.statementList) : nullptr;
	declarationList = other.declarationList ? new vector<Declaration*>(*other.declarationList) : nullptr;
	return *this;
}

