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
		Expression(AssignmentExpression* ae);
		Expression(Expression* exp, string operation, AssignmentExpression* ae);
		Expression();
		virtual ~Expression();

	private:
		Expression* exp;
		string oper;
		AssignmentExpression* ae;
	};
}
