#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "AssignmentExpression.h"

namespace WadeSpace {
	class Initializer
	{
	public:
		Initializer(AssignmentExpression& exp);
		Initializer(std::vector<Initializer>& list);
		Initializer();
		~Initializer();
	private:
		std::optional < std::reference_wrapper < AssignmentExpression>> exp;
		std::optional < std::reference_wrapper < std::vector<Initializer>>> list;
	};
}
