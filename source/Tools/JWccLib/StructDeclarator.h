#pragma once

#include "Declarator.h"

namespace WadeSpace
{
	class ExpressionTree;

	class StructDeclarator
	{
		Declarator* declarator;
		ExpressionTree* constantExpression;
	public:
		StructDeclarator() = default;
		StructDeclarator(Declarator* declarator);
		StructDeclarator(ExpressionTree* constantExpression);
		StructDeclarator(Declarator* declarator, ExpressionTree* constantExpression);
		virtual ~StructDeclarator() = default;
		StructDeclarator(const StructDeclarator& other) = default;
		StructDeclarator(StructDeclarator&& other) noexcept = default;
		StructDeclarator& operator=(const StructDeclarator& other) = default;
		StructDeclarator& operator=(StructDeclarator&& other) noexcept = default;
		[[nodiscard]] Declarator* getDeclarator() const { return declarator; }
		[[nodiscard]] ExpressionTree* getConstantExpression() const { return constantExpression; }
		[[nodiscard]] bool hasDeclarator() const { return declarator != nullptr; }
		[[nodiscard]] bool hasConstantExpression() const { return constantExpression != nullptr; }
		void setDeclarator(Declarator* declarator) { this->declarator = declarator; }
		void setConstantExpression(ExpressionTree* constantExpression) { this->constantExpression = constantExpression; }
	};
}
