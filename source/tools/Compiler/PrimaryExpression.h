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
		PrimaryExpression(Constant* c);
		PrimaryExpression(Expression* exp);
		PrimaryExpression();
		virtual ~PrimaryExpression();
	private:
		string identifier;
		Constant* c;
		Expression* exp;
	};
}
