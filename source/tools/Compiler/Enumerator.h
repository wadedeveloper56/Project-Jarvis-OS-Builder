#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "ConstantExpression.h"

namespace WadeSpace {
	class Enumerator
	{
	public:
		Enumerator(std::string value, ConstantExpression&type);
		Enumerator(std::string value);
		Enumerator();
		~Enumerator();
	private:
		std::string operatorStr;
		std::optional<std::reference_wrapper < ConstantExpression>> expression;
	};
}
