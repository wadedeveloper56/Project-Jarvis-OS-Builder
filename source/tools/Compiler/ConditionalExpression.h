#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "LogicalOrExpression.h"

using namespace std;

namespace WadeSpace
{
	class Expression;

	class ConditionalExpression
	{
	public:
		ConditionalExpression(LogicalOrExpression* logicalOrExpression);
		ConditionalExpression(LogicalOrExpression* logicalOrExpression, Expression* expression, ConditionalExpression* conditionalExpression);
		ConditionalExpression();
		virtual ~ConditionalExpression();

	private:
		LogicalOrExpression* logicalOrExpression;
		Expression* expression;
		ConditionalExpression* conditionalExpression;
	};
}
