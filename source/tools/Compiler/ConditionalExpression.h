#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "LogicalOrExpression.h"
#include "ConditionalExpression.h"

using namespace std;

namespace WadeSpace {
	class Expression;

	class ConditionalExpression
	{
	public:
		ConditionalExpression(LogicalOrExpression& ce);
		ConditionalExpression(LogicalOrExpression& loe, Expression& exp, ConditionalExpression& ce);
		ConditionalExpression();
		~ConditionalExpression();
	private:
		optional < reference_wrapper < LogicalOrExpression>> loe;
		optional < reference_wrapper < Expression>> exp;
		optional < reference_wrapper < ConditionalExpression>> ce;
	};
}
