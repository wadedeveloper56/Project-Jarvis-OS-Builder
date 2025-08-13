#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"

namespace WadeSpace
{
	class AbstractDeclarator;
	class ConstantExpression;
	class ParameterTypeList;
	class ExpressionNode;

	class DirectAbstractDeclarator
	{
	public:
		DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, ParameterTypeList* parameterTypeList, TokenType type);
		DirectAbstractDeclarator(ParameterTypeList* parameterTypeList, TokenType type);
		DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, ExpressionNode* constantExpression, TokenType type);
		DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, TokenType type);
		DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator);
		DirectAbstractDeclarator(ExpressionNode* constantExpression);
		DirectAbstractDeclarator(TokenType type);
		DirectAbstractDeclarator();
		virtual ~DirectAbstractDeclarator();

	private:
		ParameterTypeList* parameterTypeList;
		DirectAbstractDeclarator* directAbstractDeclarator;
		AbstractDeclarator* abstractDeclarator;
		ExpressionNode* constantExpression;
		TokenType type;
	};
}
