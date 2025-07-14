#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Declarator.h"
#include "ConstantExpression.h"

namespace WadeSpace {
	class StructDeclarator
	{
	public:
		StructDeclarator(Declarator& dec);
		StructDeclarator(ConstantExpression& exp);
		StructDeclarator(Declarator& dec, ConstantExpression& exp);
		StructDeclarator();
		~StructDeclarator();
	private:
		std::optional < std::reference_wrapper < Declarator>> dec;
		std::optional < std::reference_wrapper < ConstantExpression>> exp;
	};
}
