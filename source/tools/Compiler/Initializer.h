#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>
#include "AssignmentExpression.h"

using namespace std;

namespace WadeSpace
{
	class Initializer
	{
	public:
		Initializer(AssignmentExpression* assignmentExpression);
		Initializer(vector<Initializer*>* initializerList);
		Initializer();
		virtual ~Initializer();
		AssignmentExpression* getAssignmentExpression() const;
		vector<Initializer*>* getInitializerList() const;

	private:
		AssignmentExpression* assignmentExpression;
		vector<Initializer*>* initializerList;
	};
}
