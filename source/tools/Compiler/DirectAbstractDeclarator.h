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

	class DirectAbstractDeclarator
	{
	public:
		DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, ParameterTypeList* parameterTypeList, TokenType type);
		DirectAbstractDeclarator(ParameterTypeList* parameterTypeList, TokenType type);
		DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, ConstantExpression* constantExpression, TokenType type);
		DirectAbstractDeclarator(DirectAbstractDeclarator* directAbstractDeclarator, TokenType type);
		DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator);
		DirectAbstractDeclarator(ConstantExpression* constantExpression);
		DirectAbstractDeclarator(TokenType type);
		DirectAbstractDeclarator();
		virtual ~DirectAbstractDeclarator();

	private:
		ParameterTypeList* parameterTypeList;
		DirectAbstractDeclarator* directAbstractDeclarator;
		AbstractDeclarator* abstractDeclarator;
		ConstantExpression* constantExpression;
		TokenType type;
	};
}
