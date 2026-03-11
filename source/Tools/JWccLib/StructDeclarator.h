#pragma once

#include "Declarator.h"

namespace WadeSpace
{
	class ExpressionTree;

	class StructDeclarator
	{
	public:
		StructDeclarator();
		StructDeclarator(Declarator* declarator);
		StructDeclarator(ExpressionTree* constantExpression);
		StructDeclarator(Declarator* declarator, ExpressionTree* constantExpression);
		virtual ~StructDeclarator();

		StructDeclarator(const StructDeclarator& other);
		StructDeclarator(StructDeclarator&& other) noexcept;
		StructDeclarator& operator=(const StructDeclarator& other);
		StructDeclarator& operator=(StructDeclarator&& other) noexcept;

		[[nodiscard]] Declarator* getDeclarator() const;
		[[nodiscard]] ExpressionTree* getConstantExpression() const;

		[[nodiscard]] bool hasDeclarator() const;
		[[nodiscard]] bool hasConstantExpression() const;

	private:
		Declarator* declarator;
		ExpressionTree* constantExpression;
	};
}
