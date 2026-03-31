#pragma once

#include "TokenType.h"
#include "Declaration.h"

using namespace std;

namespace WadeSpace
{
	class ExpressionTree;

	class BaseStatement
	{
	public:
		BaseStatement(TokenType op, CTokenPtr identifier, ExpressionTree* const exp, ExpressionTree* const contExp, 
			BaseStatement* const statement, BaseStatement* const es1, BaseStatement* const es2,
			BaseStatement* const statement2, vector<BaseStatement*>* const statementList,
			vector<Declaration*>* const declarationList);
		explicit BaseStatement(TokenType op);
		BaseStatement(TokenType op, CTokenPtr identifier);
		BaseStatement(TokenType op, ExpressionTree* exp);
		BaseStatement(TokenType op, ExpressionTree* exp, BaseStatement* statement);
		BaseStatement(TokenType op, ExpressionTree* exp, BaseStatement* ifStatement, BaseStatement* elseStatement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, ExpressionTree* exp, BaseStatement* statement);
		explicit BaseStatement(vector<BaseStatement*>* statementList);
		explicit BaseStatement(vector<Declaration*>* declarationList);
		BaseStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList);
		BaseStatement(CTokenPtr identifier, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* statement);
		BaseStatement() = default;
		virtual ~BaseStatement();

		BaseStatement(const BaseStatement& other);
		BaseStatement(BaseStatement&& other) noexcept;
		BaseStatement& operator=(const BaseStatement& other);
		BaseStatement& operator=(BaseStatement&& other) noexcept;

		[[nodiscard]] TokenType getOp() const;
		[[nodiscard]] CTokenPtr getIdentifier() const;
		[[nodiscard]] ExpressionTree* getExp() const;
		[[nodiscard]] ExpressionTree* getContExp() const;
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
		CTokenPtr identifier;
		ExpressionTree* exp;
		ExpressionTree* contExp;
		BaseStatement* statement;
		BaseStatement* es1;
		BaseStatement* es2;
		BaseStatement* statement2;
		vector<BaseStatement*>* statementList;
		vector<Declaration*>* declarationList;
	};
}
