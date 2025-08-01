#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "ExclusiveOrExpression.h"

using namespace std;

namespace WadeSpace
{
	class InclusiveOrExpression
	{
	public:
		InclusiveOrExpression(ExclusiveOrExpression* exclusiveOrExpression);
		InclusiveOrExpression(InclusiveOrExpression* inclusiveOrExpression, ExclusiveOrExpression* exclusiveOrExpression);
		InclusiveOrExpression();
		virtual ~InclusiveOrExpression();
		InclusiveOrExpression* getInclusiveOrExpression() const;
		ExclusiveOrExpression* getExclusiveOrExpression() const;

	private:
		InclusiveOrExpression* inclusiveOrExpression;
		ExclusiveOrExpression* exclusiveOrExpression;
	};
}
