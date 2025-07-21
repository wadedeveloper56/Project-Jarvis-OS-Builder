#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "BaseStatement.h"

using namespace std;

namespace WadeSpace {
    class ExpressionStatement : public BaseStatement
	{
	public:
		ExpressionStatement(Expression* exp);
		ExpressionStatement();
		virtual ~ExpressionStatement();
	};
}
