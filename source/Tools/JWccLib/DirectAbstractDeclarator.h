#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"

namespace WadeSpace
{
	class AbstractDeclarator;
	class ConstantExpression;
	class ParameterTypeList;
	class Expression;

	class DirectAbstractDeclarator
	{
	public:
		DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, ParameterTypeList* parameterTypeList, TokenType type);
		DirectAbstractDeclarator(ParameterTypeList* parameterTypeList, TokenType type);
		DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, Expression* constantExpression, TokenType type);
		DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, TokenType type);
		DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator);
		DirectAbstractDeclarator(Expression* constantExpression);
		DirectAbstractDeclarator(TokenType type);
		DirectAbstractDeclarator();
		virtual ~DirectAbstractDeclarator();

	private:
		ParameterTypeList* parameterTypeList;
		DirectAbstractDeclarator* directAbstractDeclarator;
		AbstractDeclarator* abstractDeclarator;
		Expression* constantExpression;
		TokenType type;
	};
}
