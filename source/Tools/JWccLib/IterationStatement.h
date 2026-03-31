#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace
{
	class IterationStatement : public BaseStatement
	{
	public:
		IterationStatement() = default;
		IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, ExpressionTree* exp, BaseStatement* statement);
		IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement);
		IterationStatement(TokenType op, ExpressionTree* identifier, BaseStatement* statement);
		virtual ~IterationStatement() = default;
		IterationStatement(const IterationStatement& other) = default;
		IterationStatement(IterationStatement&& other) noexcept = default;
		IterationStatement& operator=(const IterationStatement& other) = default;
		IterationStatement& operator=(IterationStatement&& other) noexcept = default;
	};
}
