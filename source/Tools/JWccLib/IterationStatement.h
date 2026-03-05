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
		IterationStatement();
		IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, Expression* exp, BaseStatement* statement);
		IterationStatement(TokenType op, BaseStatement* es1, BaseStatement* es2, BaseStatement* statement);
		IterationStatement(TokenType op, Expression* identifier, BaseStatement* statement);
		virtual ~IterationStatement();

		IterationStatement(const IterationStatement& other);
		IterationStatement(IterationStatement&& other) noexcept;
		IterationStatement& operator=(const IterationStatement& other);
		IterationStatement& operator=(IterationStatement&& other) noexcept;
	};
}
