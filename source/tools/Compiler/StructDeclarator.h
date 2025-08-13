#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "Declarator.h"
#include "ConstantExpression.h"

namespace WadeSpace
{
	class ExpressionNode;

	class StructDeclarator
	{
	public:
		StructDeclarator(Declarator* declarator);
		StructDeclarator(ExpressionNode* constantExpression);
		StructDeclarator(Declarator* declarator, ExpressionNode* constantExpression);
		StructDeclarator();
		virtual ~StructDeclarator();
		Declarator* getDeclarator() const;
		ExpressionNode* getConstantExpression() const;

	private:
		Declarator* declarator;
		ExpressionNode* constantExpression;
	};
}
