#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include "Expression.h"

namespace WadeSpace {
	class Enumerator
	{
	public:
		Enumerator(std::string value, Expression *type);
		Enumerator();
		~Enumerator();

		std::string getoperator() const;
		Expression getExpression() const;
	private:
		std::string operatorStr;
		Expression *expression;
	};
}
