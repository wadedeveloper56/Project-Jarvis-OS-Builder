#pragma once

#include <string>
#include <vector>
#include <optional>

using namespace std;

namespace WadeSpace
{
	class Expression;

	class Initializer
	{
	public:
		Initializer(Expression* assignmentExpression);
		Initializer(vector<Initializer*>* initializerList);
		Initializer();
		virtual ~Initializer();
		Expression* getAssignmentExpression() const;
		vector<Initializer*>* getInitializerList() const;

	private:
		Expression* assignmentExpression;
		vector<Initializer*>* initializerList;
	};
}
