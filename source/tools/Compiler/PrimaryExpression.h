#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "Constant.h"

using namespace std;

namespace WadeSpace
{
	class Expression;

	class PrimaryExpression
	{
	public:
		PrimaryExpression(const string& identifier);
		PrimaryExpression(Constant* constant);
		PrimaryExpression(Expression* expression);
		PrimaryExpression();
		virtual ~PrimaryExpression();
		optional<string> getIdentifier() const;
		Constant* getConstant() const;
		Expression* getExpression() const;

	private:
		optional<string> identifier;
		Constant* constant;
		Expression* expression;
	};
}
