#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "AssignmentExpression.h"

using namespace std;

namespace WadeSpace
{
	class ExpressionNode;

	class Initializer
	{
	public:
		Initializer(ExpressionNode* assignmentExpression);
		Initializer(vector<Initializer*>* initializerList);
		Initializer();
		virtual ~Initializer();
		ExpressionNode* getAssignmentExpression() const;
		vector<Initializer*>* getInitializerList() const;

	private:
		ExpressionNode* assignmentExpression;
		vector<Initializer*>* initializerList;
	};
}
