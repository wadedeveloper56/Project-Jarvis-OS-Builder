#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "InclusiveOrExpression.h"

using namespace std;

namespace WadeSpace {
	class LogicalAndExpression
	{
	public:
		LogicalAndExpression(InclusiveOrExpression* eoe);
		LogicalAndExpression(LogicalAndExpression* loe, InclusiveOrExpression* eoe);
		LogicalAndExpression();
		~LogicalAndExpression();
	private:
		InclusiveOrExpression* ioe;
		LogicalAndExpression* lae;
	};
}
