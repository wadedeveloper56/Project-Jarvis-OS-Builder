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

		DirectAbstractDeclaratorNode() = default;
		DirectAbstractDeclaratorNode(ParameterTypeList* const parameterTypeList, ExpressionTree* const constantExpression, optional<TokenType> type);
		~DirectAbstractDeclaratorNode() = default;
	}* DirectAbstractDeclaratorNodePtr;

	class DirectAbstractDeclarator
	{
		AbstractDeclarator* abstractDeclarator;
		vector<DirectAbstractDeclaratorNode*>* list;
	public:
		DirectAbstractDeclarator() = default;
		DirectAbstractDeclarator(AbstractDeclarator* abstractDeclarator, vector<DirectAbstractDeclaratorNode*>* list);
		virtual ~DirectAbstractDeclarator() = default;
		DirectAbstractDeclarator(const DirectAbstractDeclarator& other) = default;
		DirectAbstractDeclarator(DirectAbstractDeclarator&& other) noexcept = default;
		DirectAbstractDeclarator& operator=(const DirectAbstractDeclarator& other) = default;
		DirectAbstractDeclarator& operator=(DirectAbstractDeclarator&& other) noexcept = default;
		[[nodiscard]] AbstractDeclarator* getAbstractDeclarator() const { return abstractDeclarator; }
		[[nodiscard]] vector<DirectAbstractDeclaratorNode*>* getList() const { return list; }
		void setAbstractDeclarator(AbstractDeclarator* abstractDeclarator) { this->abstractDeclarator = abstractDeclarator; }
		void setList(vector<DirectAbstractDeclaratorNode*>* list) { this->list = list; }
		bool hasAbstractDeclarator() const { return abstractDeclarator != nullptr; }
		bool hasList() const { return list != nullptr && !list->empty(); }
	};
}
