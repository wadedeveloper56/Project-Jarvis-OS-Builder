#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Expression.h"

namespace WadeSpace {
	class Enumerator
	{
	public:
		Enumerator(std::string value, Expression &type);
		Enumerator(std::string value);
		Enumerator();
		~Enumerator();

		std::string getoperator() const;
		Expression& getExpression() const;
	private:
		std::string operatorStr;
		std::optional<std::reference_wrapper < Expression>> expression;
	};
}
