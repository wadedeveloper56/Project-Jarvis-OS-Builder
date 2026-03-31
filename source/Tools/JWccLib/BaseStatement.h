#pragma once

#include "TokenType.h"
#include "Declaration.h"

using namespace std;

namespace WadeSpace
{
	class ExpressionTree;

	class BaseStatement
	{
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
	public:
		BaseStatement(TokenType op, CTokenPtr identifier, ExpressionTree* const exp, ExpressionTree* const contExp,
			BaseStatement* const statement, BaseStatement* const es1, BaseStatement* const es2,
			BaseStatement* const statement2, vector<BaseStatement*>* const statementList,
			vector<Declaration*>* const declarationList);
		BaseStatement(TokenType op);
		BaseStatement(TokenType op, CTokenPtr identifier);
		BaseStatement(TokenType op, ExpressionTree* exp);
		BaseStatement(TokenType op, ExpressionTree* exp, BaseStatement* statement);
		BaseStatement(TokenType op, ExpressionTree* exp, BaseStatement* ifStatement, BaseStatement* elseStatement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, ExpressionTree* exp, BaseStatement* statement);
		BaseStatement(vector<BaseStatement*>* statementList);
		BaseStatement(vector<Declaration*>* declarationList);
		BaseStatement(vector<BaseStatement*>* statementList, vector<Declaration*>* declarationList);
		BaseStatement(CTokenPtr identifier, BaseStatement* statement);
		BaseStatement(TokenType op, BaseStatement* statement);
		BaseStatement() = default;
		virtual ~BaseStatement() = default;
		BaseStatement(const BaseStatement& other) = default;
		BaseStatement(BaseStatement&& other) noexcept = default;
		BaseStatement& operator=(const BaseStatement& other) = default;
		BaseStatement& operator=(BaseStatement&& other) noexcept = default;
		[[nodiscard]] TokenType getOp() const { return op; }
		[[nodiscard]] CTokenPtr getIdentifier() const { return identifier; }
		[[nodiscard]] ExpressionTree* getExp() const { return exp; }
		[[nodiscard]] ExpressionTree* getContExp() const { return contExp; }
		[[nodiscard]] BaseStatement* getStatement() const { return statement; }
		[[nodiscard]] BaseStatement* getEs1() const { return es1; }
		[[nodiscard]] BaseStatement* getEs2() const { return es2; }
		[[nodiscard]] BaseStatement* getStatement2() const { return statement2; }
		[[nodiscard]] vector<BaseStatement*>* getStatementList() const { return statementList; }
		[[nodiscard]] vector<Declaration*>* getDeclarationList() const { return declarationList; }
		void setOp(TokenType op) { this->op = op; }
		void setIdentifier(CTokenPtr identifier) { this->identifier = identifier; }
		void setExp(ExpressionTree* exp) { this->exp = exp; }
		void setContExp(ExpressionTree* contExp) { this->contExp = contExp; }
		void setStatement(BaseStatement* statement) { this->statement = statement; }
		void setEs1(BaseStatement* es1) { this->es1 = es1; }
		void setEs2(BaseStatement* es2) { this->es2 = es2; }
		void setStatement2(BaseStatement* statement2) { this->statement2 = statement2; }
		void setStatementList(vector<BaseStatement*>* statementList) { this->statementList = statementList; }
		void setDeclarationList(vector<Declaration*>* declarationList) { this->declarationList = declarationList; }
		[[nodiscard]] bool hasIdentifier() const { return identifier != nullptr; }
		[[nodiscard]] bool hasExp() const { return exp != nullptr; }
		[[nodiscard]] bool hasContExp() const { return contExp != nullptr; }
		[[nodiscard]] bool hasStatement() const { return statement != nullptr; }
		[[nodiscard]] bool hasEs1() const { return es1 != nullptr; }
		[[nodiscard]] bool hasEs2() const { return es2 != nullptr; }
		[[nodiscard]] bool hasStatement2() const { return statement2 != nullptr; }
		[[nodiscard]] bool hasStatementList() const { return statementList != nullptr; }
		[[nodiscard]] bool hasDeclarationList() const { return declarationList != nullptr; }

	};
}
