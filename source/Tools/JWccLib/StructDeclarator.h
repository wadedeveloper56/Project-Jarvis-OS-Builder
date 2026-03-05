#pragma once

#include "Declarator.h"

namespace WadeSpace
{
	class Expression;

	class StructDeclarator
	{
	public:
		StructDeclarator();
		StructDeclarator(Declarator* declarator);
		StructDeclarator(Expression* constantExpression);
		StructDeclarator(Declarator* declarator, Expression* constantExpression);
		virtual ~StructDeclarator();

		StructDeclarator(const StructDeclarator& other);
		StructDeclarator(StructDeclarator&& other) noexcept;
		StructDeclarator& operator=(const StructDeclarator& other);
		StructDeclarator& operator=(StructDeclarator&& other) noexcept;

		[[nodiscard]] Declarator* getDeclarator() const;
		[[nodiscard]] Expression* getConstantExpression() const;

		[[nodiscard]] bool hasDeclarator() const;
		[[nodiscard]] bool hasConstantExpression() const;

	private:
		Declarator* declarator;
		Expression* constantExpression;
	};
}
