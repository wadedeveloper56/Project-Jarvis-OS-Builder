#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Expression.h"

namespace WadeSpace {
	class Initializer
	{
	public:
		Initializer(Expression& exp);
		Initializer(std::vector<Initializer>& list);
		Initializer();
		~Initializer();
	private:
		std::optional < std::reference_wrapper < Expression>> exp;
		std::optional < std::reference_wrapper < std::vector<Initializer>>> list;
	};
}
