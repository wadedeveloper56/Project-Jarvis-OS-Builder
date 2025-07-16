#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

using namespace std;

namespace WadeSpace {
	class Expression;

	class BaseStatement
	{
	public:
		BaseStatement(TokenType op);
		BaseStatement(TokenType op, string identifier);
		BaseStatement(TokenType op, Expression& exp);
		BaseStatement(TokenType op, Expression& exp, BaseStatement& statement);
		BaseStatement(TokenType op, BaseStatement& es1, BaseStatement& es2, BaseStatement& statement);
		BaseStatement(TokenType op, BaseStatement& es1, BaseStatement& es2, Expression& exp, BaseStatement& statement);
		BaseStatement();
		~BaseStatement();
	protected:
		TokenType op;
		string identifier;
		optional < reference_wrapper < Expression>> exp;
		optional < reference_wrapper < BaseStatement>> statement;
		optional < reference_wrapper < BaseStatement>> es1;
		optional < reference_wrapper < BaseStatement>> es2;
	};
}
