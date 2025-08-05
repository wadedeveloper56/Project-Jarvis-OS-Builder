#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "TokenType.h"
#include "PrimaryExpression.h"
#include "AssignmentExpression.h"
#include "TypeName.h"
#include "Initializer.h"

using namespace std;

namespace WadeSpace
{
	class Expression;

	typedef struct _PostfixExpression
	{
		Expression* expression;
		optional<int> str1;
		optional<string> str2;
		optional<int> str3;
		vector<AssignmentExpression*>* vectorAssignmentExpression;
	} PostfixExpressionNode, * PostfixExpressionNodePtr;

	class PostfixExpression
	{
	public:
		PostfixExpression(PrimaryExpression* primaryExpression);
		PostfixExpression(TypeName* typeName, vector<Initializer*>* vectorInitializer);
		PostfixExpression();
		virtual ~PostfixExpression();

		void add(int str, int str2);
		void add(int str, string& str2);
		void add(Expression* expression);
		void add(vector<AssignmentExpression*>* vectorAssignmentExpression);

		PrimaryExpression* getPrimaryExpression() const;
		vector<Initializer*>* getVectorInitializer() const;
		vector<PostfixExpressionNode*>* getVectorPostfixExpressionNode() const;
		TypeName* getTypeName() const;

	private:
		PrimaryExpression* primaryExpression;
		vector<Initializer*>* vectorInitializer;
		vector<PostfixExpressionNode*>* vectorPostfixExpressionNode;
		TypeName* typeName;
	};
}
