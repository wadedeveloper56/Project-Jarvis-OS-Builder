#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "Expression.h"
#include "Declaration.h"

using namespace std;

namespace WadeSpace
{
	class BaseStatement
	{
	public:
		BaseStatement(TokenType op);
		BaseStatement(TokenType op, string& identifier);
		BaseStatement(TokenType op, Expression* exp);
		BaseStatement(TokenType op, Expression* exp, BaseStatement* statement);
		BaseStatement(TokenType op, Expression* exp, BaseStatement* ifStatement, BaseStatement* elseStatement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, Expression* exp, BaseStatement* statement);
		BaseStatement(vector<BaseStatement*>* statementList);
		BaseStatement(vector<Declaration*>* declarationList);
		BaseStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList);
		BaseStatement(string&  identifier, BaseStatement* statement);
		BaseStatement(TokenType op, ConstantExpression* exp, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* statement);
		BaseStatement();
		virtual ~BaseStatement();
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
