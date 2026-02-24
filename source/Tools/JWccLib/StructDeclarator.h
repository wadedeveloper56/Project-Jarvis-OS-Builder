#pragma once

#include <string>
#include <vector>
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
		StructDeclarator(const StructDeclarator& other);
		StructDeclarator(StructDeclarator&& other) noexcept;
		StructDeclarator& operator=(const StructDeclarator& other);
		StructDeclarator& operator=(StructDeclarator&& other) noexcept;

	private:
		Declarator* declarator;
		Expression* constantExpression;
	};
}
