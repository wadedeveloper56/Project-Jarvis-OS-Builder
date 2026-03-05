#pragma once

#include <string>
#include <vector>
#include <optional>

#include "Token.h"

using namespace std;

namespace WadeSpace
{
	class Expression;

	class Enumerator
	{
	public:
		Enumerator(TokenPtr identifier, Expression* constantExpression);
		Enumerator();
		virtual ~Enumerator();

		Enumerator(const Enumerator& other);
		Enumerator(Enumerator&& other) noexcept;
		Enumerator& operator=(const Enumerator& other);
		Enumerator& operator=(Enumerator&& other) noexcept;
	
		[[nodiscard]] TokenPtr getIdentifier() const;
		[[nodiscard]] Expression* getConstantExpression() const;

		[[nodiscard]] bool hasIdentifier() const { return identifier != nullptr; }
		[[nodiscard]] bool hasConstantExpression() const { return constantExpression != nullptr; }

	private:
		TokenPtr identifier;
		Expression* constantExpression;
	};
}
