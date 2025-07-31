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
		Expression(Expression* expression, const string& operation, AssignmentExpression* assignmentExpression);
		Expression();
		virtual ~Expression();

	private:
		Expression* expression;
		optional<string> oper;
		AssignmentExpression* assignmentExpression;
	};
}
