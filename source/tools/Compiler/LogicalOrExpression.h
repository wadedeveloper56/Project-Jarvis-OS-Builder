#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "LogicalAndExpression.h"

using namespace std;

namespace WadeSpace
{
	class LogicalOrExpression
	{
	public:
		LogicalOrExpression(LogicalAndExpression* logicalAndExpression);
		LogicalOrExpression(LogicalOrExpression* logicalOrExpression, LogicalAndExpression* logicalAndExpression);
		LogicalOrExpression();
		virtual ~LogicalOrExpression();
		LogicalOrExpression* getLogicalOrExpression() const;
		LogicalAndExpression* getLogicalAndExpression() const;

	private:
		LogicalOrExpression* logicalOrExpression;
		LogicalAndExpression* logicalAndExpression;
	};
}
