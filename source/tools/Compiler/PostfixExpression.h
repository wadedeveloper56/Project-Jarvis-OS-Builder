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

namespace WadeSpace {
	class Expression;

	class PostfixExpression
	{
	public:
		PostfixExpression(PrimaryExpression* pe);
		PostfixExpression(PostfixExpression* pfe, string str, string str2);
		PostfixExpression(PostfixExpression* pfe, Expression* exp);
		PostfixExpression(PostfixExpression* pfe, vector<AssignmentExpression *>* aev);
		PostfixExpression(TypeName* tn, vector<Initializer *>* iv);
		PostfixExpression();
		~PostfixExpression();
	private:
		PrimaryExpression* pe;
		PostfixExpression* pfe;
		Expression* exp;
		vector<AssignmentExpression*>* aev;
		vector<Initializer*>* iv;
		TypeName* tn;
		string str1;
		string str2;
	};
}
