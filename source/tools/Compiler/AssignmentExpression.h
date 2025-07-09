#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Expression.h"

namespace WadeSpace {
	class AssignmentExpression : public Expression
	{
	public:
		AssignmentExpression();
		AssignmentExpression(Expression& left);
		AssignmentExpression(Expression& left, AssignmentOperator& ao, Expression& right);
	};
}
