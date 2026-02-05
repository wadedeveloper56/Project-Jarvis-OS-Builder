#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Declarator.h"

namespace WadeSpace
{
	class Expression;

	class StructDeclarator
	{
	public:
		StructDeclarator(Declarator* declarator);
		StructDeclarator(Expression* constantExpression);
		StructDeclarator(Declarator* declarator, Expression* constantExpression);
		StructDeclarator();
		virtual ~StructDeclarator();
		Declarator* getDeclarator() const;
		Expression* getConstantExpression() const;

	private:
		Declarator* declarator;
		Expression* constantExpression;
	};
}
