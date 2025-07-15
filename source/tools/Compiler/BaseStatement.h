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
		BaseStatement(TokenType op, Expression& identifier);
		BaseStatement();
		~BaseStatement();
	private:
		TokenType op;
		string identifier;
		optional < reference_wrapper < Expression>> exp;
	};
}
