#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "AssignmentExpression.h"

using namespace std;

namespace WadeSpace {
	class Expression
	{
	public:
		Expression(AssignmentExpression& ae);
		Expression(Expression& exp, string operation, AssignmentExpression& ae);
		Expression();
		~Expression();
	private:
		optional < reference_wrapper < Expression>> exp;
		string oper;
		optional < reference_wrapper < AssignmentExpression>> ae;

	};
}

