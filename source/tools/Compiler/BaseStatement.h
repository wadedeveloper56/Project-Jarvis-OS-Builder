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
	class ExpressionNode;

	class BaseStatement
	{
	public:
		BaseStatement(TokenType op);
		BaseStatement(TokenType op, string& identifier);
		BaseStatement(TokenType op, ExpressionNode* exp);
		BaseStatement(TokenType op, ExpressionNode* exp, BaseStatement* statement);
		BaseStatement(TokenType op, ExpressionNode* exp, BaseStatement* ifStatement, BaseStatement* elseStatement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, ExpressionNode* exp, BaseStatement* statement);
		BaseStatement(vector<BaseStatement*>* statementList);
		BaseStatement(vector<Declaration*>* declarationList);
		BaseStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList);
		BaseStatement(string&  identifier, BaseStatement* statement);
		//BaseStatement(TokenType op, ExpressionNode* exp, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* statement);
		BaseStatement();
		virtual ~BaseStatement();
		optional<string> getIdentifier() const;
		ExpressionNode* getExp() const;
		ExpressionNode* getContExp() const;
		BaseStatement* getStatement() const;
		BaseStatement* getEs1() const;
		BaseStatement* getEs2() const;
		BaseStatement* getStatement2() const;
		vector<BaseStatement*>* getStatementList() const;
		vector<Declaration*>* getDeclarationList() const;

	protected:
		TokenType op;
		optional<string> identifier;
		ExpressionNode* exp;
		ExpressionNode* contExp;
		BaseStatement* statement;
		BaseStatement* es1;
		BaseStatement* es2;
		BaseStatement* statement2;
		vector<BaseStatement*>* statementList;
		vector<Declaration*>* declarationList;
	};
}
