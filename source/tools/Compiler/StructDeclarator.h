#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Declarator.h"
#include "ConstantExpression.h"

namespace WadeSpace
{
	class StructDeclarator
	{
	public:
		StructDeclarator(Declarator* declarator);
		StructDeclarator(ConstantExpression* constantExpression);
		StructDeclarator(Declarator* declarator, ConstantExpression* constantExpression);
		StructDeclarator();
		virtual ~StructDeclarator();
		Declarator* getDeclarator() const;
		ConstantExpression* getConstantExpression() const;

	private:
		Declarator* declarator;
		ConstantExpression* constantExpression;
	};
}
