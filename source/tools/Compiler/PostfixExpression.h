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

	class PostfixExpression
	{
	public:
		PostfixExpression(PrimaryExpression* primaryExpression);
		PostfixExpression(PostfixExpression* postfixExpression, const string& str, const string& str2);
		PostfixExpression(PostfixExpression* postfixExpression, Expression* expression);
		PostfixExpression(PostfixExpression* postfixExpression, vector<AssignmentExpression*>* vectorAssignmentExpression);
		PostfixExpression(TypeName* typeName, vector<Initializer*>* vectorInitializer);
		PostfixExpression();
		virtual ~PostfixExpression();
		PrimaryExpression* getPrimaryExpression() const;
		PostfixExpression* getPostfixExpression() const;
		Expression* getExpression() const;
		vector<AssignmentExpression*>* getVectorAssignmentExpression() const;
		vector<Initializer*>* getVectorInitializer() const;
		TypeName* getTypeName() const;
		optional<string> getStr1() const;
		optional<string> getStr2() const;

	private:
		PrimaryExpression* primaryExpression;
		PostfixExpression* postfixExpression;
		Expression* expression;
		vector<AssignmentExpression*>* vectorAssignmentExpression;
		vector<Initializer*>* vectorInitializer;
		TypeName* typeName;
		optional<string> str1;
		optional<string> str2;
	};
}
