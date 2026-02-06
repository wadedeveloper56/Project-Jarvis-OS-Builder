#pragma once

#include <string>
#include <vector>
#include <optional>
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
			const optional<string>& identifier, 
			const optional<int>& token1, 
			const optional<int>& token2,
			Declarator* const declarator, 
			DirectDeclarator* const directDeclarator,
			Expression* const constantExpression, 
			ParameterTypeList* const parameterTypeList,
			vector<string>* const vectorOfStrings
		);
		~DirectDeclarator() = default;
		DirectDeclarator(const DirectDeclarator& other) = default;
		DirectDeclarator(DirectDeclarator&& other) = default;
		DirectDeclarator& operator=(const DirectDeclarator& other) = default;
		DirectDeclarator& operator=(DirectDeclarator&& other) = default;

		[[nodiscard]] optional<string> getIdentifier() const;
		[[nodiscard]] optional<int> getToken1() const;
		[[nodiscard]] optional<int> getToken2() const;
		[[nodiscard]] Declarator* getDeclarator() const;
		[[nodiscard]] DirectDeclarator* getDirectDeclarator() const;
		[[nodiscard]] Expression* getConstantExpression() const;
		[[nodiscard]] ParameterTypeList* getParameterTypeList() const;
		[[nodiscard]] vector<string>* getVectorOfStrings() const;

		[[nodiscard]] bool isIdentifier() const { return identifier.has_value(); }
		[[nodiscard]] bool isToken1() const { return token1.has_value(); }
		[[nodiscard]] bool isToken2() const { return token2.has_value(); }
		[[nodiscard]] bool isDeclarator() const { return declarator != nullptr; }
		[[nodiscard]] bool isDirectDeclarator() const { return directDeclarator != nullptr; }
		[[nodiscard]] bool isConstantExpression() const { return constantExpression != nullptr; }
		[[nodiscard]] bool isParameterTypeList() const { return parameterTypeList != nullptr; }
		[[nodiscard]] bool isVectorOfStrings() const { return vectorOfStrings != nullptr; }

	private:
		optional<string> identifier;
		optional<int> token1;
		optional<int> token2;
		Declarator* declarator;
		DirectDeclarator* directDeclarator;
		Expression* constantExpression;
		ParameterTypeList* parameterTypeList;
		vector<string>* vectorOfStrings;
	};
}
