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
	public:
		DirectDeclarator( 
			TokenPtr identifier, 
			TokenPtr token1,
			TokenPtr token2,
			Declarator* const declarator, 
			DirectDeclarator* const directDeclarator,
			ExpressionTree* const constantExpression, 
			ParameterTypeList* const parameterTypeList,
			vector<TokenPtr>* const vectorOfStrings
		);
		~DirectDeclarator();

		DirectDeclarator(const DirectDeclarator& other);
		DirectDeclarator(DirectDeclarator&& other) noexcept;
		DirectDeclarator& operator=(const DirectDeclarator& other);
		DirectDeclarator& operator=(DirectDeclarator&& other) noexcept;

		[[nodiscard]] TokenPtr getIdentifier() const;
		[[nodiscard]] TokenPtr getToken1() const;
		[[nodiscard]] TokenPtr getToken2() const;
		[[nodiscard]] Declarator* getDeclarator() const;
		[[nodiscard]] DirectDeclarator* getDirectDeclarator() const;
		[[nodiscard]] ExpressionTree* getConstantExpression() const;
		[[nodiscard]] ParameterTypeList* getParameterTypeList() const;
		[[nodiscard]] vector<TokenPtr>* getVectorOfStrings() const;

		[[nodiscard]] bool hasIdentifier() const { return identifier != nullptr; }
		[[nodiscard]] bool hasToken1() const { return token1 != nullptr; }
		[[nodiscard]] bool hasToken2() const { return token2 != nullptr; }
		[[nodiscard]] bool hasDeclarator() const { return declarator != nullptr; }
		[[nodiscard]] bool hasDirectDeclarator() const { return directDeclarator != nullptr; }
		[[nodiscard]] bool hasConstantExpression() const { return constantExpression != nullptr; }
		[[nodiscard]] bool hasParameterTypeList() const { return parameterTypeList != nullptr; }
		[[nodiscard]] bool hasVectorOfStrings() const { return vectorOfStrings != nullptr; }

	private:
		TokenPtr identifier;
		TokenPtr token1;
		TokenPtr token2;
		Declarator* declarator;
		DirectDeclarator* directDeclarator;
		ExpressionTree* constantExpression;
		ParameterTypeList* parameterTypeList;
		vector<TokenPtr>* vectorOfStrings;
	};
}
