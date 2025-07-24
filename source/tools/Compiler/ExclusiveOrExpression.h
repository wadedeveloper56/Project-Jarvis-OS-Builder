#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "AndExpression.h"

using namespace std;

namespace WadeSpace
{
	class ExclusiveOrExpression
	{
	public:
		ExclusiveOrExpression(AndExpression* andExpression);
		ExclusiveOrExpression(ExclusiveOrExpression* exclusiveOrExpression, AndExpression* andExpression);
		ExclusiveOrExpression();
		virtual ~ExclusiveOrExpression();
		AndExpression* getAndExpression() const;
		ExclusiveOrExpression* getExclusiveOrExpression() const;

	private:
		AndExpression* andExpression;
		ExclusiveOrExpression* exclusiveOrExpression;
	};
}
