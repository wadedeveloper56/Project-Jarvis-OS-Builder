#pragma once

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
		Initializer(const Initializer& other);
		Initializer(Initializer&& other) noexcept;
		Initializer& operator=(const Initializer& other);
		Initializer& operator=(Initializer&& other) noexcept;
		virtual ~Initializer();
		Expression* getAssignmentExpression() const;
		vector<Initializer*>* getInitializerList() const;

	private:
		Expression* assignmentExpression;
		vector<Initializer*>* initializerList;
	};
}
