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
		CTokenPtr identifier;
		ExpressionTree* constantExpression;
	public:
		Enumerator() = default;
		Enumerator(CTokenPtr identifier, ExpressionTree* constantExpression);
		virtual ~Enumerator() = default;
		Enumerator(const Enumerator& other) = default;
		Enumerator(Enumerator&& other) noexcept = default;
		Enumerator& operator=(const Enumerator& other) = default;
		Enumerator& operator=(Enumerator&& other) noexcept = default;
		[[nodiscard]] CTokenPtr getIdentifier() const { return identifier; }
		[[nodiscard]] ExpressionTree* getConstantExpression() const { return constantExpression; }
		void setIdentifier(CTokenPtr identifier) { this->identifier = identifier; }
		void setConstantExpression(ExpressionTree* constantExpression) { this->constantExpression = constantExpression; }
		bool hasConstantExpression() const { return constantExpression != nullptr; }
		bool hasIdentifier() const { return identifier != nullptr; }
	};
}
