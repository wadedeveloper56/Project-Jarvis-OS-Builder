#pragma once

#include <string>
#include <vector>
#include <optional>

#include "Token.h"
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class ConstantExpression;
	class ParameterTypeList;
	class Declarator;
	class Expression;

	class DirectDeclarator
	{
	public:
		DirectDeclarator(
			TokenPtr identifier, 
			TokenPtr token1,
			TokenPtr token2,
			Declarator* const declarator, 
			DirectDeclarator* const directDeclarator,
			Expression* const constantExpression, 
			ParameterTypeList* const parameterTypeList,
			vector<TokenPtr>* const vectorOfStrings
		);
		~DirectDeclarator() = default;
		DirectDeclarator(const DirectDeclarator& other) = default;
		DirectDeclarator(DirectDeclarator&& other) = default;
		DirectDeclarator& operator=(const DirectDeclarator& other) = default;
		DirectDeclarator& operator=(DirectDeclarator&& other) = default;

		[[nodiscard]] TokenPtr getIdentifier() const;
		[[nodiscard]] TokenPtr getToken1() const;
		[[nodiscard]] TokenPtr getToken2() const;
		[[nodiscard]] Declarator* getDeclarator() const;
		[[nodiscard]] DirectDeclarator* getDirectDeclarator() const;
		[[nodiscard]] Expression* getConstantExpression() const;
		[[nodiscard]] ParameterTypeList* getParameterTypeList() const;
		[[nodiscard]] vector<TokenPtr>* getVectorOfStrings() const;

		[[nodiscard]] bool isIdentifier() const { return identifier != nullptr; }
		[[nodiscard]] bool isToken1() const { return token1 != nullptr; }
		[[nodiscard]] bool isToken2() const { return token2 != nullptr; }
		[[nodiscard]] bool isDeclarator() const { return declarator != nullptr; }
		[[nodiscard]] bool isDirectDeclarator() const { return directDeclarator != nullptr; }
		[[nodiscard]] bool isConstantExpression() const { return constantExpression != nullptr; }
		[[nodiscard]] bool isParameterTypeList() const { return parameterTypeList != nullptr; }
		[[nodiscard]] bool isVectorOfStrings() const { return vectorOfStrings != nullptr; }

	private:
		TokenPtr identifier;
		TokenPtr token1;
		TokenPtr token2;
		Declarator* declarator;
		DirectDeclarator* directDeclarator;
		Expression* constantExpression;
		ParameterTypeList* parameterTypeList;
		vector<TokenPtr>* vectorOfStrings;
	};
}
