#pragma once

#include "Token.h"
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class ConstantExpression;
	class ParameterTypeList;
	class Declarator;
	class ExpressionTree;

	class DirectDeclarator
	{
		CTokenPtr identifier;
		CTokenPtr token1;
		CTokenPtr token2;
		Declarator* declarator;
		DirectDeclarator* directDeclarator;
		ExpressionTree* constantExpression;
		ParameterTypeList* parameterTypeList;
		vector<CTokenPtr>* vectorOfStrings;
	public:
		DirectDeclarator() = default;
		DirectDeclarator( 
			CTokenPtr identifier, 
			CTokenPtr token1,
			CTokenPtr token2,
			Declarator* const declarator, 
			DirectDeclarator* const directDeclarator,
			ExpressionTree* const constantExpression, 
			ParameterTypeList* const parameterTypeList,
			vector<CTokenPtr>* const vectorOfStrings
		);
		virtual ~DirectDeclarator() = default;
		DirectDeclarator(const DirectDeclarator& other) = default;
		DirectDeclarator(DirectDeclarator&& other) noexcept = default;
		DirectDeclarator& operator=(const DirectDeclarator& other) = default;
		DirectDeclarator& operator=(DirectDeclarator&& other) noexcept = default;
		[[nodiscard]] CTokenPtr getIdentifier() const { return identifier; };
		[[nodiscard]] CTokenPtr getToken1() const { return token1; };
		[[nodiscard]] CTokenPtr getToken2() const { return token2; };
		[[nodiscard]] Declarator* getDeclarator() const { return declarator; };
		[[nodiscard]] DirectDeclarator* getDirectDeclarator() const { return directDeclarator; };
		[[nodiscard]] ExpressionTree* getConstantExpression() const { return constantExpression; };
		[[nodiscard]] ParameterTypeList* getParameterTypeList() const { return parameterTypeList; };
		[[nodiscard]] vector<CTokenPtr>* getVectorOfStrings() const { return vectorOfStrings; };
		void setIdentifier(CTokenPtr const identifier) { this->identifier = identifier; };
		void setToken1(CTokenPtr const token1) { this->token1 = token1; };
		void setToken2(CTokenPtr const token2) { this->token2 = token2; };
		void setDeclarator(Declarator* const declarator) { this->declarator = declarator; };
		void setDirectDeclarator(DirectDeclarator* const directDeclarator) { this->directDeclarator = directDeclarator; };
		void setConstantExpression(ExpressionTree* const constantExpression) { this->constantExpression = constantExpression; };
		void setParameterTypeList(ParameterTypeList* const parameterTypeList) { this->parameterTypeList = parameterTypeList; };
		void setVectorOfStrings(vector<CTokenPtr>* const vectorOfStrings) { this->vectorOfStrings = vectorOfStrings; };
		[[nodiscard]] bool hasIdentifier() const { return identifier != nullptr; };
		[[nodiscard]] bool hasToken1() const { return token1 != nullptr; };
		[[nodiscard]] bool hasToken2() const { return token2 != nullptr; };
		[[nodiscard]] bool hasDeclarator() const { return declarator != nullptr; };
		[[nodiscard]] bool hasDirectDeclarator() const { return directDeclarator != nullptr; };
		[[nodiscard]] bool hasConstantExpression() const { return constantExpression != nullptr; };
		[[nodiscard]] bool hasParameterTypeList() const { return parameterTypeList != nullptr; };
		[[nodiscard]] bool hasVectorOfStrings() const { return vectorOfStrings != nullptr; };

	};
}
