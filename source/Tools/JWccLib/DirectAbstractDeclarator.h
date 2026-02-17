#pragma once

#include <string>
#include <vector>
#include <optional>
#include "TokenType.h"

using namespace std;

namespace WadeSpace
{
	class DirectAbstractDeclarator;
	class AbstractDeclarator;
	class ConstantExpression;
	class ParameterTypeList;
	class Expression;

	typedef struct DirectAbstractDeclaratorNode
	{
		ParameterTypeList* parameterTypeList;
		Expression* constantExpression;
		TokenType type;
		
		DirectAbstractDeclaratorNode() = default;

		DirectAbstractDeclaratorNode(ParameterTypeList* const parameterTypeList, Expression* const constantExpression, TokenType type)
			: parameterTypeList(parameterTypeList),
		      constantExpression(constantExpression), 
		      type(type)
		{
		}
	}* DirectAbstractDeclaratorNodePtr;

	class DirectAbstractDeclarator
	{
	public:
		DirectAbstractDeclarator(const DirectAbstractDeclarator& copy) = default;
		DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator, vector<DirectAbstractDeclaratorNode*>* list);
		DirectAbstractDeclarator();
		virtual ~DirectAbstractDeclarator() = default;
		[[nodiscard]] AbstractDeclarator* getAbstractDeclarator() const;
		[[nodiscard]] vector<DirectAbstractDeclaratorNode*>* getList() const;
	private:
		AbstractDeclarator* abstractDeclarator;
		vector<DirectAbstractDeclaratorNode*>* list;
	};
}
