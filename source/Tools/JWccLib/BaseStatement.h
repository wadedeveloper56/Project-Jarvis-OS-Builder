#pragma once

#include "TokenType.h"
#include "Declaration.h"

using namespace std;

namespace WadeSpace
{
	class Expression;

	class BaseStatement
	{
	public:
		BaseStatement(TokenType op, TokenPtr identifier, Expression* const exp, Expression* const contExp, 
			BaseStatement* const statement, BaseStatement* const es1, BaseStatement* const es2,
			BaseStatement* const statement2, vector<BaseStatement*>* const statementList,
			vector<Declaration*>* const declarationList);
		explicit BaseStatement(TokenType op);
		BaseStatement(TokenType op, TokenPtr identifier);
		BaseStatement(TokenType op, Expression* exp);
		BaseStatement(TokenType op, Expression* exp, BaseStatement* statement);
		BaseStatement(TokenType op, Expression* exp, BaseStatement* ifStatement, BaseStatement* elseStatement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, Expression* exp, BaseStatement* statement);
		explicit BaseStatement(vector<BaseStatement*>* statementList);
		explicit BaseStatement(vector<Declaration*>* declarationList);
		BaseStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList);
		BaseStatement(TokenPtr identifier, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* statement);
		BaseStatement() = default;
		virtual ~BaseStatement();

		BaseStatement(const BaseStatement& other);
		BaseStatement(BaseStatement&& other) noexcept;
		BaseStatement& operator=(const BaseStatement& other);
		BaseStatement& operator=(BaseStatement&& other) noexcept;

		[[nodiscard]] TokenType getOp() const;
		[[nodiscard]] TokenPtr getIdentifier() const;
		[[nodiscard]] Expression* getExp() const;
		[[nodiscard]] Expression* getContExp() const;
		[[nodiscard]] BaseStatement* getStatement() const;
		[[nodiscard]] BaseStatement* getEs1() const;
		[[nodiscard]] BaseStatement* getEs2() const;
		[[nodiscard]] BaseStatement* getStatement2() const;
		[[nodiscard]] vector<BaseStatement*>* getStatementList() const;
		[[nodiscard]] vector<Declaration*>* getDeclarationList() const;

		[[nodiscard]] bool hasIdentifier() const;
		[[nodiscard]] bool hasExp() const;
		[[nodiscard]] bool hasContExp() const;
		[[nodiscard]] bool hasStatement() const;
		[[nodiscard]] bool hasEs1() const;
		[[nodiscard]] bool hasEs2() const;
		[[nodiscard]] bool hasStatement2() const;
		[[nodiscard]] bool hasStatementList() const;
		[[nodiscard]] bool hasDeclarationList() const;

	protected:
		TokenType op;
		TokenPtr identifier;
		Expression* exp;
		Expression* contExp;
		BaseStatement* statement;
		BaseStatement* es1;
		BaseStatement* es2;
		BaseStatement* statement2;
		vector<BaseStatement*>* statementList;
		vector<Declaration*>* declarationList;
	};
}
