#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "Constant.h"

using namespace std;

namespace WadeSpace {
	class Expression;

	class PrimaryExpression
	{
	public:
		PrimaryExpression(string identifier);
		PrimaryExpression(Constant& c);
		PrimaryExpression(Expression& exp);
		PrimaryExpression();
		~PrimaryExpression();
	private:
		string identifier;
		optional < reference_wrapper < Constant>> c;
		optional < reference_wrapper < Expression>> exp;
	};
}
