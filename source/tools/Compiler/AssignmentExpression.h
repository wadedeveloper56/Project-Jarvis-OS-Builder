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
		AssignmentExpression(ConditionalExpression &ce);
		AssignmentExpression(UnaryExpression& ue,AssignmentOperator oper,AssignmentExpression& ae);
		AssignmentExpression();
		~AssignmentExpression();
	private:
		optional < reference_wrapper < ConditionalExpression>> ce;
		optional < reference_wrapper < UnaryExpression>> ue;
		optional < reference_wrapper < AssignmentOperator>> oper;
		optional < reference_wrapper < AssignmentExpression>> ae;

	};
}
