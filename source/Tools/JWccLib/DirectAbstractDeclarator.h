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
	class ExpressionTree;

	typedef struct DirectAbstractDeclaratorNode
	{
		ParameterTypeList* parameterTypeList;
		ExpressionTree* constantExpression;
		optional<TokenType> type;

		DirectAbstractDeclaratorNode();
		DirectAbstractDeclaratorNode(ParameterTypeList* const parameterTypeList, ExpressionTree* const constantExpression, optional<TokenType> type);
		~DirectAbstractDeclaratorNode();
	}* DirectAbstractDeclaratorNodePtr;

	class DirectAbstractDeclarator
	{
	public:
		DirectAbstractDeclarator();
		DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator, vector<DirectAbstractDeclaratorNode*>* list);
		virtual ~DirectAbstractDeclarator();

		DirectAbstractDeclarator(const DirectAbstractDeclarator& other);
		DirectAbstractDeclarator(DirectAbstractDeclarator&& other) noexcept;
		DirectAbstractDeclarator& operator=(const DirectAbstractDeclarator& other);
		DirectAbstractDeclarator& operator=(DirectAbstractDeclarator&& other) noexcept;

		[[nodiscard]] AbstractDeclarator* getAbstractDeclarator() const;
		[[nodiscard]] vector<DirectAbstractDeclaratorNode*>* getList() const;

		[[nodiscard]] bool hasAbstractDeclarator() const;
		[[nodiscard]] bool hasList() const;

	private:
		AbstractDeclarator* abstractDeclarator;
		vector<DirectAbstractDeclaratorNode*>* list;
	};
}
