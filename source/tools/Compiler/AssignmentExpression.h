#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "UnaryExpression.h"
#include "ConditionalExpression.h"
#include "AssignmentOperator.h"

using namespace std;

namespace WadeSpace {
	class AssignmentExpression
	{
	public:
		AssignmentExpression(ConditionalExpression* ce);
		AssignmentExpression(UnaryExpression* ue, AssignmentOperator* oper, AssignmentExpression* ae);
		AssignmentExpression();
		virtual ~AssignmentExpression();
	private:
		ConditionalExpression* ce;
		UnaryExpression* ue;
		AssignmentOperator* oper;
		AssignmentExpression* ae;

	};
}
