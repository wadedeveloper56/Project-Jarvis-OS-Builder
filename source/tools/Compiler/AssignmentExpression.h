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

namespace WadeSpace
{
	class AssignmentExpression
	{
	public:
		AssignmentExpression(ConditionalExpression* conditionalExpression);
		AssignmentExpression(UnaryExpression* unaryExpression, AssignmentOperator* oper, AssignmentExpression* assignmentExpression);
		AssignmentExpression();
		virtual ~AssignmentExpression();
		ConditionalExpression* getConditionalExpression() const;
		UnaryExpression* getUnaryExpression() const;
		AssignmentOperator* getAssignmentOperator() const;
		AssignmentExpression* getAssignmentExpression() const;

	private:
		ConditionalExpression* conditionalExpression;
		UnaryExpression* unaryExpression;
		AssignmentOperator* oper;
		AssignmentExpression* assignmentExpression;
	};
}
