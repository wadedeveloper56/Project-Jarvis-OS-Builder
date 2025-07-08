#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Declarator.h"
#include "Expression.h"

namespace WadeSpace {
	class StructDeclarator
	{
	public:
		StructDeclarator(Declarator& dec);
		StructDeclarator(Expression& exp);
		StructDeclarator(Declarator& dec, Expression& exp);
		StructDeclarator();
		~StructDeclarator();
		Declarator& getDec() const;
		Expression& getExp() const;
	private:
		std::optional < std::reference_wrapper < Declarator>> dec;
		std::optional < std::reference_wrapper < Expression>> exp;
	};
}
