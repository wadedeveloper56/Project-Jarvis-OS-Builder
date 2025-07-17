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
		StructDeclarator(Declarator* dec);
		StructDeclarator(ConstantExpression* exp);
		StructDeclarator(Declarator* dec, ConstantExpression* exp);
		StructDeclarator();
		~StructDeclarator();
	private:
		Declarator* dec;
		ConstantExpression* exp;
	};
}
