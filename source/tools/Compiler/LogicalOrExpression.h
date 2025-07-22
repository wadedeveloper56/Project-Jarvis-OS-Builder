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
		LogicalOrExpression(LogicalAndExpression* lae);
		LogicalOrExpression(LogicalOrExpression* loe, LogicalAndExpression* lae);
		LogicalOrExpression();
		virtual ~LogicalOrExpression();

	private:
		LogicalOrExpression* loe;
		LogicalAndExpression* lae;
	};
}
