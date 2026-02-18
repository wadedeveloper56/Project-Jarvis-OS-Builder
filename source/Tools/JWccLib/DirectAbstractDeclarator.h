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
		optional<TokenType> type;

		DirectAbstractDeclaratorNode();
		DirectAbstractDeclaratorNode(ParameterTypeList* const parameterTypeList, Expression* const constantExpression,
		                             optional<TokenType> type);
		~DirectAbstractDeclaratorNode();
	}* DirectAbstractDeclaratorNodePtr;

	class DirectAbstractDeclarator
	{
	public:
		DirectAbstractDeclarator(const DirectAbstractDeclarator& copy) = default;
		DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator, vector<DirectAbstractDeclaratorNode*>* list);
		DirectAbstractDeclarator();
		virtual ~DirectAbstractDeclarator();
		[[nodiscard]] AbstractDeclarator* getAbstractDeclarator() const;
		[[nodiscard]] vector<DirectAbstractDeclaratorNode*>* getList() const;

	private:
		AbstractDeclarator* abstractDeclarator;
		vector<DirectAbstractDeclaratorNode*>* list;
	};
}
