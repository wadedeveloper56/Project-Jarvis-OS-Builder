#pragma once

#include <string>
#include <vector>
#include <optional>

#include "Token.h"

using namespace std;

namespace WadeSpace
{
	class ExpressionTree;

	class Enumerator
	{
	public:
		Enumerator(TokenPtr identifier, ExpressionTree* constantExpression);
		Enumerator();
		virtual ~Enumerator();

		Enumerator(const Enumerator& other);
		Enumerator(Enumerator&& other) noexcept;
		Enumerator& operator=(const Enumerator& other);
		Enumerator& operator=(Enumerator&& other) noexcept;
	
		[[nodiscard]] TokenPtr getIdentifier() const;
		[[nodiscard]] ExpressionTree* getConstantExpression() const;

		[[nodiscard]] bool hasIdentifier() const { return identifier != nullptr; }
		[[nodiscard]] bool hasConstantExpression() const { return constantExpression != nullptr; }

	private:
		TokenPtr identifier;
		ExpressionTree* constantExpression;
	};
}
