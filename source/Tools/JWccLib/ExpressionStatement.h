#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace
{
	class ExpressionStatement : public BaseStatement
	{
	public:
		ExpressionStatement(Expression* exp);
		ExpressionStatement();
		virtual ~ExpressionStatement() = default;

		ExpressionStatement(const ExpressionStatement& other);
		ExpressionStatement(ExpressionStatement&& other) noexcept;
		ExpressionStatement& operator=(const ExpressionStatement& other);
		ExpressionStatement& operator=(ExpressionStatement&& other) noexcept;
	};
}
