#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "Declaration.h"

using namespace std;

namespace WadeSpace
{
	class Expression;

	class BaseStatement
	{
	public:
		BaseStatement(TokenType op);
		BaseStatement(TokenType op, string identifier);
		BaseStatement(TokenType op, Expression* exp);
		BaseStatement(TokenType op, Expression* exp, BaseStatement* statement);
		BaseStatement(TokenType op, Expression* exp, BaseStatement* ifStatement, BaseStatement* elseStatement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, Expression* exp, BaseStatement* statement);
		BaseStatement(vector<BaseStatement*>* statementList);
		BaseStatement(vector<Declaration*>* declarationList);
		BaseStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList);
		BaseStatement(string identifier, BaseStatement* statement);
		BaseStatement(TokenType op, ConstantExpression* exp, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* statement);
		BaseStatement();
		virtual ~BaseStatement();
		string get_identifier() const;
		Expression* get_exp() const;
		ConstantExpression* get_cont_exp() const;
		BaseStatement* get_statement() const;
		BaseStatement* get_es1() const;
		BaseStatement* get_es2() const;
		BaseStatement* get_statement2() const;
		vector<BaseStatement*>* get_statement_list() const;
		vector<Declaration*>* get_declaration_list() const;

	protected:
		TokenType op;
		string identifier;
		Expression* exp;
		ConstantExpression* contExp;
		BaseStatement* statement;
		BaseStatement* es1;
		BaseStatement* es2;
		BaseStatement* statement2;
		vector<BaseStatement*>* statementList;
		vector<Declaration*>* declarationList;
	};
}
