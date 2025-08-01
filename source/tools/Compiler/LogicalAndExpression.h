#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "InclusiveOrExpression.h"

using namespace std;

namespace WadeSpace
{
	class LogicalAndExpression
	{
	public:
		LogicalAndExpression(InclusiveOrExpression* inclusiveOrExpression);
		LogicalAndExpression(LogicalAndExpression* logicalAndExpression, InclusiveOrExpression* inclusiveOrExpression);
		LogicalAndExpression();
		virtual ~LogicalAndExpression();
		InclusiveOrExpression* getInclusiveOrExpression() const;
		LogicalAndExpression* getLogicalAndExpression() const;

	private:
		InclusiveOrExpression* inclusiveOrExpression;
		LogicalAndExpression* logicalAndExpression;
	};
}
