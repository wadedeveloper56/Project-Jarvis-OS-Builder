#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "AssignmentExpression.h"

using namespace std;

namespace WadeSpace
{
	class Expression
	{
	public:
		Expression(AssignmentExpression* assignmentExpression);
		Expression(Expression* expression, const int& operation, AssignmentExpression* assignmentExpression);
		Expression();
		virtual ~Expression();
		Expression* getExpression() const;
		optional<int> getOper() const;
		AssignmentExpression* getAssignmentExpression() const;

	private:
		Expression* expression;
		optional<int> oper;
		AssignmentExpression* assignmentExpression;
	};
}
